#include <game/scenemanager.h>

SceneManager* SceneManager::GetInstance() {
    if (!instance) {
        instance = new SceneManager();
    }
    return instance;
}

template<typename T>
T* SceneManager::RegisterScene(const char* name) {
    static_assert(std::is_base_of<Scene, T>::value, "T must inherit from Scene");
    auto scene = std::make_unique<T>(name);
    T* scenePtr = scene.get();
    scenes.push_back(std::move(scene));
    return scenePtr;
}

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
