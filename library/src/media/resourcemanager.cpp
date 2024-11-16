#include <media/resourcemanager.h>

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
