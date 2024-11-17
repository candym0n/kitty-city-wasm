#pragma once

#include <emscripten.h>
#include <stdint.h>

#define NULL_IMAGE 0

// The struct for passing information about audio
struct js_image {
    uint32_t numImage;  // The number of image things
    uint32_t loaded;    // The number of image things loaded
};

// An image ID
typedef uint32_t image_t;

// Register an image
image_t register_image(const char *path);

// Where image information is stored
extern struct js_image *image_location;

// Get information about image
inline uint32_t get_total_images() {
    return image_location->numImage;
}

inline uint32_t get_loaded_images() {
    return image_location->loaded;
}

extern "C" {
    // Get the location in memory where events will be passed
    EMSCRIPTEN_KEEPALIVE js_image* get_image_location();
}
