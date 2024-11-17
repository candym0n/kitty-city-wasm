#pragma once

#include <library.h>
#include <vector>
#include <functional>

// A callback function for a button press
using ButtonCallback = std::function<void()>;

class Button : public Component {
private:
    int width;          // The width of the button
    int height;         // The height of the button
    image_t img;        // The image on the button
    image_t click_img;  // The image of the button when clicked
    image_t hover_img;  // The image of the button when hoverd
    color_t shade;      // The color of the shade
    std::vector<ButtonCallback> pressed; // List of functions to call when the button is pressed
    std::vector<ButtonCallback> hover;   // List of functions to call when the button is hovered
    std::vector<ButtonCallback> clicked; // List of functions to call when the button is done being clicked
    std::vector<ButtonCallback> out;     // List of functions to call when the button is no longer in the vicinity of the pointer
public:
    enum BUTTON_STATE {
        OFF,    // The pointer is not in the vicinity of the button
        HOVER,  // The pointer is on but not pressed on the button
        PRESS   // The pointer is pressing down on the button
    };

    // A button event
    enum BUTTON_EVENT {
        HOVERED,    // Called when the button has just been hovered
        CLICKED,    // Called when the button is done being clicked
        PRESSED,    // Called when the button has just been pressed
        OUT,        // Called when the button is no longer in the vicinity of the pointer
    };

    // The current state of the button
    BUTTON_STATE state;

    // Initialize those variables
    Button() : state(OFF), shade(0x000000), Component() {};

    // Set the image to be drawn
    void SetImage(image_t image);
    void SetImage(const char* src);
    void SetImage(BUTTON_STATE forState, image_t image);
    void SetImage(BUTTON_STATE forState, const char* src);

    // Set the dimensions
    void SetDimensions(int w, int h);

    // Called once per frame
    void Update() override;

    // Add an event listener (callback) when an event happens
    void AddCallback(BUTTON_EVENT event, ButtonCallback callback);
};
