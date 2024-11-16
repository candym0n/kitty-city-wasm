#include <components/renderer/imagerenderer.h>

void ImageRenderer::SetImage(const char *path)
{
    image = register_image(path);
}

void ImageRenderer::SetImage(image_t img)
{
    image = img;
}

void ImageRenderer::SetDimensions(int w, int h)
{
    width = w;
    height = h;
}

void ImageRenderer::SetRotation(int rot)
{
    rotation = rot;
}

void ImageRenderer::SetVisibility(bool state)
{
    visible = state;
}

void ImageRenderer::Update()
{
    // Check that there is actually an image
    if (!visible || !image) return;

    // Draw the image
    draw_image(owner->GetPosition(), width, height, image, rotation);
}
