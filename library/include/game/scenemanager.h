#pragma once

#include <vector>
#include <game/scene.h>
#include <memory>
#include <string.h>

// Singleton class for scene management
class SceneManager {
private:
    std::vector<std::unique_ptr<Scene>> scenes;
    Scene* activeScene;
    static SceneManager* instance;  // Singleton instance

    SceneManager() : activeScene(nullptr) {}

public:
    static SceneManager* GetInstance();

    // Register a new scene
    template<typename T>
    T* RegisterScene(const char* name);

    // Load a scene by name
    void LoadScene(const char* name);

    // Called every frame
    void Update();

    // Get the current scene that is active
    Scene* GetActiveScene() const { return activeScene; }
};
