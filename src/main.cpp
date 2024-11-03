#include <emscripten.h>
#include <unistd.h>
#include <javascript.h>
#include <media.h>

bool loaded = false;

image_t img;

extern "C" EMSCRIPTEN_KEEPALIVE void update(void) {
    clear_screen();
    if (mouse_down() && is_playing()) {
        pause_background_music();
        draw_image(Vector2<int>(100, 100), 100, 100, img);
    } else if (!is_playing()) {
        play_background_music();
    }
}

EMSCRIPTEN_KEEPALIVE int main(void) {
    img = register_image("head.png");
    play_background_music();
}
