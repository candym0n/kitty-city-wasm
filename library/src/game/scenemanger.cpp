#include <game/scenemanager.h>

std::vector<std::unique_ptr<Scene>> SceneManager::scenes;
Scene* SceneManager::activeScene;

void SceneManager::LoadScene(const char* name) {
    Scene* newScene = nullptr;
    
    // Find the requested scene
    for (auto& scene : scenes) {
        if (strcmp(scene->GetName(), name) == 0) {
            newScene = scene.get();
            break;
        }
    }

    if (!newScene) return;

    // Unload current scene if exists
    if (activeScene) {
        activeScene->OnUnload();
    }

    // Set and load new scene
    activeScene = newScene;
    activeScene->OnLoad();
}

void SceneManager::Update() {
    if (activeScene) {
        activeScene->Update();
    }
}
