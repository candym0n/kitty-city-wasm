#include <emscripten.h>
#include <unistd.h>
#include <javascript.h>
#include <game.h>

GameObject *test;
GameObject *music;

uint64_t last_time;

extern "C" EMSCRIPTEN_KEEPALIVE void update(void) {
    clear_screen();

    // Every second toggle the music (sounds very annoying, but this is just for testing)
    if (get_timestamp() - last_time > 1000) {
        music->GetComponent<BackgroundMusic>()->Toggle();
        last_time = get_timestamp();
    }

    test->GetComponent<ImageRenderer>()->Update();
    music->GetComponent<BackgroundMusic>()->Update();
}

EMSCRIPTEN_KEEPALIVE int main(void) {
    test = new GameObject();

    // Add an image renderer
    test->AddComponent<ImageRenderer>();
    test->GetComponent<ImageRenderer>()->SetImage("head.png");
    test->GetComponent<ImageRenderer>()->SetDimensions(500, 500);

    // Add background music
    music = new GameObject();
    music->AddComponent<BackgroundMusic>();
    music->GetComponent<BackgroundMusic>()->SetPlayOnStart(true);
    music->Init();
}
