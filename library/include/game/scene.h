#pragma once
#include <vector>
#include <memory>
#include <game/gameobject.h>
#include <stdbool.h>

// Base class for scenes
class Scene {
private:
    // The game objects within the scene
    std::vector<std::unique_ptr<GameObject>> gameObjects;

    // Is this scene loaded?
    bool isLoaded;

    // The name of the scene
    const char* name;

public:
    Scene(const char* sceneName) : isLoaded(false), name(sceneName) {}
    virtual ~Scene() = default;

    // Called when scene is first loaded
    virtual void OnLoad() { isLoaded = true; }
    
    // Called when scene is unloaded
    virtual void OnUnload() { isLoaded = false; }

    // Called every frame when scene is active
    virtual void Update();

    // Create (and add) a game object to this scene
    GameObject* CreateGameObject();

    // Destroy a game object that is in this scene
    void DestroyGameObject(GameObject* obj);

    // Get the name of the scene
    const char* GetName() const { return name; }

    // Is the scene loaded?
    bool IsLoaded() const { return isLoaded; }
};
