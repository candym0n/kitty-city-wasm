#include <scenes/gamescene.h>

void GameScene::Update()
{
    clear_screen();
    draw_image(Vector2<int>::zero(), 1600, 900, tbd);
}
