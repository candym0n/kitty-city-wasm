#include <game/scene.h>

void Scene::Update() {
    
    for (auto& obj : gameObjects) {
        obj->Update();
    }
}

GameObject* Scene::CreateGameObject() {
    auto gameObject = std::make_unique<GameObject>();
    GameObject* ptr = gameObject.get();
    gameObjects.push_back(std::move(gameObject));
    return ptr;
}

void Scene::DestroyGameObject(GameObject* obj) {
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
        if (it->get() == obj) {
            gameObjects.erase(it);
            break;
        }
    }
}

