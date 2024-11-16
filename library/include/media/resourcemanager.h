#pragma once

#include <vector>
#include <game.h>
#include <media.h>

// Singleton class to manage and preload resources
class ResourceManager {
public:
    // Get loading progress for images
    static float GetImageLoadProgress();

    // Get loading progress for audio
    static float GetAudioLoadProgress();

    // Get total loading progress
    static float GetTotalLoadProgress();
};
