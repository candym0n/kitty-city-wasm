#include <emscripten.h>
#include <unistd.h>
#include <javascript.h>
#include <game.h>
#include <media.h>

GameObject *test;
GameObject *music;

uint64_t last_time;

ResourceManager* manager;

extern "C" EMSCRIPTEN_KEEPALIVE void update(void) {
    clear_screen();

    // Every second toggle the music and play chomp noise (sounds very annoying, but this is just for testing)
    if (get_timestamp() - last_time > 1000) {
        music->GetComponent<BackgroundMusic>()->Toggle();
        test->GetComponent<AudioSource>()->Play();
        last_time = get_timestamp();
    }

    test->GetComponent<ImageRenderer>()->Update();
    music->GetComponent<BackgroundMusic>()->Update();
}

EMSCRIPTEN_KEEPALIVE int main(void) {
    test = new GameObject();

    // Resource manager
    manager = ResourceManager::GetInstance();
    image_t head = manager->PreloadImage("head.png");
    audio_t chomp = manager->PreloadAudio("nom.mp3");

    // Add an image renderer
    test->AddComponent<ImageRenderer>();
    test->GetComponent<ImageRenderer>()->SetImage(head);
    test->GetComponent<ImageRenderer>()->SetDimensions(500, 500);

    // Add an audio source
    test->AddComponent<AudioSource>();
    test->GetComponent<AudioSource>()->SetAudio(chomp);

    // Add background music
    music = new GameObject();
    music->AddComponent<BackgroundMusic>();
    music->GetComponent<BackgroundMusic>()->SetPlayOnStart(true);
    music->Init();
}
