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

    // Draw the shade on the top based on the current state of the button and call the functions
    switch (state) {
        case PRESS:
            draw_rect(owner->GetPosition(), width, height, shade, 0, 0.5f);
            break;
        case HOVER:
            draw_rect(owner->GetPosition(), width, height, shade, 0, 0.2f);
            break;
        default:
            break;
    }

    // Draw the image of the button
    draw_image(owner->GetPosition(), width, height, img);
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
