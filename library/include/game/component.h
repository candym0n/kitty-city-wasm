#pragma once

#include <game/gameobject.h>

class GameObject;

// The base class for functionality
class Component {
protected:
    // Which game object has this component?
    GameObject* owner;

public:
    Component() : owner(nullptr) {}
    virtual ~Component() = default;

    // Called when a component is first added
    virtual void Init() {};

    // Called every frame
    virtual void Update() {};

    // Called when the game object is activated
    virtual void OnEnable() {};

    // Called when the game object is deactivated
    virtual void OnDisable() {};

    void SetOwner(GameObject* newOwner) { owner = newOwner; }
    constexpr GameObject* GetOwner() { return owner; }
};
