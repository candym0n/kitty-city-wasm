#include <media/image.h>

// Imported JavaScript functions
EM_JS(image_t, RegisterImage, (const char *path), {})

struct js_image* image_location;

image_t register_image(const char *path) {
    return RegisterImage(path);
}

extern "C" js_image* get_image_location() {
    // Allocate some block of memory for events
    image_location = static_cast<struct js_image*>(malloc(sizeof(struct js_image)));
    return image_location;
}
