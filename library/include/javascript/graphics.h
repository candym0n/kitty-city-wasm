#pragma once

#include <emscripten.h>
#include <stdint.h>
#include <math/vector.h>
#include <media/image.h>

// Color
typedef uint32_t color_t;

// Draw a rectangle
void draw_rect(Vector2<int> position, int width, int height, color_t color, int rotation=0, float opacity=1.0f);

// Clear the screen
void clear_screen(void);

// Clear a single rectangle
void clear_rect(Vector2<int> position, int width, int height);

// Draw an image
void draw_image(Vector2<int> position, int width, int height, image_t image, int rotation=0);
