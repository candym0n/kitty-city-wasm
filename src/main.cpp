#include <library.h>
#include <math.h>
#include <scenes/loadingscene.h>
#include <scenes/gamescene.h>

// Called once per frame
extern "C" EMSCRIPTEN_KEEPALIVE void update(void) {
    SceneManager::Update();
}

// Called at the start
EMSCRIPTEN_KEEPALIVE int main(void) {
    // Setup the scenes
    SceneManager::RegisterScene<LoadingScene>("LoadingScene");
    SceneManager::RegisterScene<GameScene>("GameScene");

    // Start at the loading scene
    SceneManager::LoadScene("LoadingScene");
}
