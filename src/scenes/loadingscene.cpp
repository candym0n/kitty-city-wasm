#include <scenes/loadingscene.h>

// The amount loaded right now
static float loaded;

LoadingScene::LoadingScene(const char * sceneName) : Scene(sceneName)
{
    // Add the loading bar
    loadingBar = CreateGameObject();

    // Setup the loading bar
    LoadingBar* bar = loadingBar->AddComponent<LoadingBar>();
    loadingBar->SetPosition(400, 450);   // Move it to the center
    bar->SetDimensions(800, 100, 10);
    bar->SetColors(0xAAAAAA, 0x3BCF57);

    // Setup the background
    background = CreateGameObject();
    ImageRenderer* back = background->AddComponent<ImageRenderer>();
    background->SetPosition(0, 0);
    back->SetImage("loading/background.png");
    back->SetVisibility(true);
    back->SetDimensions(1600, 900);
    background->SetActive(false);
}

void LoadingScene::Update()
{
    // Update every object
    Scene::Update();

    // Get the amount loaded
    loaded = ResourceManager::GetTotalLoadProgress();

    // Check if we have loaded fully
    if (loaded >= 1.0f && !loadedFully) {
        loadingBar->SetActive(false);
        background->SetActive(true);
    }
}
