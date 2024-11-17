#pragma once
#include <library.h>

class LoadingScene : public Scene {
private:
    // The loading bar
    GameObject* loadingBar;

    // The background
    GameObject* background;

    // The start button
    GameObject* startButton;

    // Has the game loaded fully?
    bool loadedFully;
public:
    LoadingScene(const char* sceneName);

    // Called once per frame
    void Update() override;
};
