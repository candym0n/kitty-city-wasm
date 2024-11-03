#pragma once

#include <game/component.h>
#include <math/vector.h>
#include <vector>
#include <memory>
#include <stdbool.h>

class Component;

// All objects of the scene derive from THIS
class GameObject {
protected:
    // The position of the game object
    Vector2<int> position;
    
    // The components this game object has
    std::vector<std::unique_ptr<Component>> components;

    // Is the game object active (in the scene)
    bool active;

public:
    GameObject() : active(true) {}
    ~GameObject() = default;

    // Add a component
    template <typename T>
    T* AddComponent()
    {
        // Check that we are actually adding a component
        static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component!");

        // Add (and initialize) the component
        auto component = std::make_unique<T>();
        component->SetOwner(this);
        component->Init();
        components.push_back(std::move(component));
        return component.get();
    }

    // Get a component
    template <typename T>
    T* GetComponent()
    {
        // Loop through every component
        for (auto& comp : components) {
            // Check that it is inherited from T
            if (T* casted = dynamic_cast<T*>(comp.get())) {
                return casted;
            }
        }

        // We found NADA ZERO ZIP
        return nullptr;
    }


    // Called once per frame
    void Update();

    // Set the active-ness of the gameobject (will also call Component functions)
    void SetActive(bool state);

    // Set the position of the gameobject
    inline constexpr void SetPosition(Vector2<int>& newPos) { position = newPos; }
    inline constexpr void SetPosition(int x, int y) { position.x = x; position.y = y; }

    // Get the position of the gameobject
    const Vector2<int>& GetPosition() const { return position; }
};
