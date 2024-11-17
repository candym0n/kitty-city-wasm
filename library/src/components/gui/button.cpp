#include <media/image.h>
#include <components/gui/button.h>

#define CALL_FUNCTIONS(list) for (ButtonCallback callback : list) callback();

void Button::SetImage(image_t image)
{
    img = image;
}

void Button::SetImage(const char* src)
{
    img = register_image(src);
}

void Button::SetImage(BUTTON_STATE forState, image_t image)
{
    switch (forState) {
        case PRESS:
            click_img = image;
            break;
        case OFF:
            SetImage(image);
            break;
        case HOVER:
            hover_img = image;
            break;
    }
}

void Button::SetImage(BUTTON_STATE forState, const char* src)
{
    SetImage(forState, register_image(src));
}

void Button::SetDimensions(int w, int h)
{
    width = w;
    height = h;
}

void Button::Update()
{
    // The previous state of the button
    BUTTON_STATE prevState = state;

    // Get the new state of the button
    bool inRect = get_mouse().inRectangle(owner->GetPosition(), width, height);
    if (inRect && !mouse_down()) {
        state = HOVER;
    } else if (inRect && mouse_down()) {
        state = PRESS;
    } else {
        state = OFF;
    }

    // Have we switched from not pressing to pressing?
    if (prevState != PRESS && state == PRESS) {
        CALL_FUNCTIONS(pressed);
    }

    // Have we switched from not hovering to hovering?
    if (prevState == OFF && state == HOVER) {
        CALL_FUNCTIONS(hover);
    }

    // Have we switched from being on the button to not?
    if (prevState != OFF && state == OFF) {
        CALL_FUNCTIONS(out);
    }

    // Have we switched from being clicked to not?
    if (prevState == PRESS && state != PRESS) {
        CALL_FUNCTIONS(clicked);
    }

    switch (state) {
        case PRESS:
            if (click_img == NULL_IMAGE) {
                draw_rect(owner->GetPosition(), width, height, shade, 0, 0.2f);
            } else {
                draw_image(owner->GetPosition(), width, height, click_img);
            }
            break;
        case HOVER:
            if (hover_img == NULL_IMAGE) {
                draw_rect(owner->GetPosition(), width, height, shade, 0, 0.5f);
            } else {
                draw_image(owner->GetPosition(), width, height, hover_img);
            }
            break;
        case OFF:
            draw_image(owner->GetPosition(), width, height, img);
            break;
    }
}

void Button::AddCallback(BUTTON_EVENT event, ButtonCallback callback)
{
    switch (event) {
        case PRESSED:
            pressed.push_back(callback);
            break;
        case CLICKED:
            clicked.push_back(callback);
            break;
        case OUT:
            out.push_back(callback);
            break;
        case HOVERED:
            hover.push_back(callback);
            break;
    }
}
