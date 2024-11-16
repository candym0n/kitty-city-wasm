#include <components/gui/loadingbar.h>

void LoadingBar::Update()
{
    // Draw the background
    draw_rect(owner->GetPosition(), width, height, borderColor);

    // Draw the loading bar
    draw_rect(owner->GetPosition() + Vector2<int>::one() * margin, width * loaded - margin * 2, height - margin * 2, loadColor);
}
