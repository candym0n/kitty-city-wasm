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
    void SetImage(const char* path);

    // Set the image to render given an image
    void SetImage(image_t img);

    // Set the dimensions of the image
    void SetDimensions(int w, int h);

    // Set the rotation of the image
    void SetRotation(int rot);

    // Set the visibility of the image
    void SetVisibility(bool state);

    // The update function (called once per frame)
    void Update();
};
