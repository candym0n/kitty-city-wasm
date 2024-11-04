#include <media/resourcemanager.h>

// Initialize the instnace
ResourceManager* ResourceManager::instance = nullptr;

ResourceManager* ResourceManager::GetInstance() {
    if (!instance) {
        instance = new ResourceManager();
    }
    return instance;
}

// Preload an image and return its ID
image_t ResourceManager::PreloadImage(const char* path) {
    image_t id = register_image(path);
    images.push_back({path, id});
    return id;
}

// Preload an audio and return its id
audio_t ResourceManager::PreloadAudio(const char* path) {
    audio_t id = register_audio(path);
    audio.push_back({path, id});
    return id;
}

// Get loading progress for images
float ResourceManager::GetImageLoadProgress() {
    if (get_total_images() == 0) return 1.0f;
    return static_cast<float>(get_loaded_images()) / get_total_images();
}

// Get loading progress for audio
float ResourceManager::GetAudioLoadProgress() {
    if (get_total_audio() == 0) return 1.0f;
    return static_cast<float>(get_loaded_audio()) / get_total_audio();
}

// Get total loading progress
float ResourceManager::GetTotalLoadProgress() {
    return (GetImageLoadProgress() + GetAudioLoadProgress()) * 0.5f;
}
