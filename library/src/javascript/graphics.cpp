#include <javascript/graphics.h>
#include <media/image.h>

// Exported Javascript functions
EM_JS(static void, DrawRect, (int x, int y, int width, int height, color_t color, int rotation, float opacity), {})
EM_JS(static void, ClearRect, (int x, int y, int width, int height), {})
EM_JS(static void, DrawImage, (int x, int y, int width, int height, image_t image, int rotation), {})

// Draw a rectangle
void draw_rect(Vector2<int> position, int width, int height, color_t color, int rotation, float opacity) {
    DrawRect(
        position.x,
        position.y,
        width,
        height,
        color,
        rotation,
        opacity
    );
}

// Clear the screen
void clear_screen(void) {
    ClearRect(0, 0, 0, 0);
}

// Clear a single rectangle
void clear_rect(Vector2<int> position, int width, int height) {
    ClearRect(
        position.x,
        position.y,
        width,
        height
    );
}

// Draw an image
void draw_image(Vector2<int> position, int width, int height, image_t image, int rotation) {
    DrawImage(
        position.x,
        position.y,
        width,
        height,
        image,
        rotation
    );
}
