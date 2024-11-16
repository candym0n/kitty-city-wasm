#include <components/renderer/animationrenderer.h>

void AnimationRenderer::AddImage(image_t id) {
    images.push_back(id);
}

void AnimationRenderer::AddImage(const char* path) {
    image_t image = register_image(path);
    images.push_back(image);
}

void AnimationRenderer::Update()
{
    
    // Draw it!
    ImageRenderer::Update();
}
