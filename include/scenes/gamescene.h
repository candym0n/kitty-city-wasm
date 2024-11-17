#pragma once

#include <library.h>

class GameScene : public Scene {
private:
    // TBD
    image_t tbd;
public:
    GameScene(const char* name) : Scene(name) {
        tbd = register_image("misc/tbd.png");
    }

    // Called once per frame
    void Update();
};
