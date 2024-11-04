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
    static ResourceManager* GetInstance();

    // Preload an image and return its ID
    image_t PreloadImage(const char* path);

    // Preload an audio and return its id
    audio_t PreloadAudio(const char* path);

    // Get loading progress for images
    float GetImageLoadProgress();

    // Get loading progress for audio
    float GetAudioLoadProgress();

    // Get total loading progress
    float GetTotalLoadProgress();
};
