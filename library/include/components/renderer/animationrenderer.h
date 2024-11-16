#pragma once
#include <library.h>
#include <vector>

class AnimationRenderer : public ImageRenderer {
private:
    // The list of images to be played (in order)
    std::vector<image_t> images;

    // A timer
    float timer = 0;

public:
    // Add an image
    void AddImage(image_t id);
    void AddImage(const char* path);

    // Called once per frame
    void Update();
};
