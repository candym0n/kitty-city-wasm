#pragma once
#include <library.h>

class LoadingBar : public Component {
private:
    int width;  // The width (including the border)
    int height; // The height (including the border)
    int margin; // Width of the border
    color_t borderColor; // The color of the border
    color_t loadColor;   // The color of the loading bar
    float loaded;        // The percent loaded
public:
    // Called once per frame
    void Update() override;

    // Set the width / height
    inline void SetDimensions(int w, int h, int m) {
        width = w;
        height = h;
        margin = m;
    }

    // Set the colors
    inline void SetColors(color_t border, color_t load) {
        borderColor = border;
        loadColor = load;
    }

    // Set the percent loaded
    inline void SetLoaded(float load) {
        loaded = load;
    }
};
