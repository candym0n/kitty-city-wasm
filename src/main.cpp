#include <emscripten.h>
#include <unistd.h>
#include <javascript.h>
#include <components/renderer/imagerenderer.h>
#include <game.h>
GameObject *test;
extern "C" EMSCRIPTEN_KEEPALIVE void update(void) {
    test->GetComponent<ImageRenderer>()->Update();
}

EMSCRIPTEN_KEEPALIVE int main(void) {
    test = new GameObject();
    test->AddComponent<ImageRenderer>();
    test->GetComponent<ImageRenderer>()->SetImage("head.png");
    test->GetComponent<ImageRenderer>()->SetDimensions(500, 500);
}
