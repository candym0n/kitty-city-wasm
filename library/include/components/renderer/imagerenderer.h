#pragma once

#include <game.h>
#include <media.h>
#include <javascript.h>

// Render things with images
class ImageRenderer : public Component {
private:
    image_t image;  // The image to render
    int width;      // The width of the image
    int height;     // The height of the image
    int rotation;   // The rotation of the image
    bool visible;   // Is this image visible?

public:
    ImageRenderer() : image(0), width(0), height(0), rotation(0), visible(true) {}

    // Set the image to render given a path
    constexpr inline void SetImage(const char* path) {
        image = register_image(path);
    }

    // Set the image to render given an image
    constexpr inline void SetImage(image_t img) {
        image = img;
    }

    // Set the dimensions of the image
    constexpr inline void SetDimensions(int w, int h) {
        width = w;
        height = h;
    }

    // Set the rotation of the image
    constexpr inline void SetRotation(int rot) {
        rotation = rot;
    }

    // Set the visibility of the image
    constexpr inline void SetVisibility(bool state) {
        visible = state;
    }

    // The update function (called once per frame)
    inline void Update() override {
        // Check that there is actually an image
        if (!visible || !image) return;

        // Draw the image
        draw_image(owner->GetPosition(), width, height, image, rotation);
    }
};
