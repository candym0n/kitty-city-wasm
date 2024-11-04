#include <game/gameobject.h>
#include <game/component.h>

void GameObject::Update()
{
    // Check if we are active
    if (!active) return;

    // Update each component
    for (auto& component : components) {
        component->Update();
    }
}

void GameObject::SetActive(bool state)
{
    // Check if we are already in this state
    if (active == state) return;

    // Set the state
    active = state;

    // Call functions within components
    for (auto& component : components) {
        if (state) component->OnEnable();
        else component->OnDisable();
    }
}

void GameObject::Init()
{
    for (auto& comp : components) {
        comp->Init();
    }
}
