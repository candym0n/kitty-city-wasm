#pragma once

#include <vector>
#include <game/scene.h>
#include <memory>
#include <string.h>

// Singleton class for scene management
class SceneManager {
private:
    static std::vector<std::unique_ptr<Scene>> scenes;
    static Scene* activeScene;

public:
    // Register a new scene
    template<typename T>
    static T* RegisterScene(const char* name) {
        static_assert(std::is_base_of<Scene, T>::value, "T must inherit from Scene");
        auto scene = std::make_unique<T>(name);
        T* scenePtr = scene.get();
        scenes.push_back(std::move(scene));
        return scenePtr;
    }

    // Load a scene by name
    static void LoadScene(const char* name);

    // Called every frame
    static void Update();

    // Get the current scene that is active
    static Scene* GetActiveScene() { return activeScene; }
};
