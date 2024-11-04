#pragma once

#include <vector>
#include <game.h>
#include <media.h>

// Singleton class to manage and preload resources
class ResourceManager {
private:
    // The singleton instance
    static ResourceManager* instance;

    struct ImageResource {
        const char* path;
        image_t id;
    };

    struct AudioResource {
        const char* path;
        audio_t id;
    };

    std::vector<ImageResource> images;
    std::vector<AudioResource> audio;

    ResourceManager() = default;

public:
    // Get / create the singleton instance
    static ResourceManager* GetInstance() {
        if (!instance) {
            instance = new ResourceManager();
        }
        return instance;
    }

    // Preload an image and return its ID
    constexpr inline image_t PreloadImage(const char* path) {
        image_t id = register_image(path);
        images.push_back({path, id});
        return id;
    }

    // Preload an audio and return its id
    constexpr inline audio_t PreloadAudio(const char* path) {
        audio_t id = register_audio(path);
        audio.push_back({path, id});
        return id;
    }

    // Get loading progress for images
    constexpr inline float GetImageLoadProgress() {
        if (get_total_images() == 0) return 1.0f;
        return static_cast<float>(get_loaded_images()) / get_total_images();
    }

    // Get loading progress for audio
    constexpr inline float GetAudioLoadProgress() {
        if (get_total_audio() == 0) return 1.0f;
        return static_cast<float>(get_loaded_audio()) / get_total_audio();
    }

    // Get total loading progress
    constexpr inline float GetTotalLoadProgress() {
        return (GetImageLoadProgress() + GetAudioLoadProgress()) * 0.5f;
    }
};
