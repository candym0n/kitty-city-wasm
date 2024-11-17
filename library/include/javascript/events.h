#pragma once

#include <stdint.h>
#include <emscripten.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math/vector.h>

// The structure for an event passed by js
struct __attribute__((packed)) js_event {
    uint32_t x;         // The x coordinate of the mouse
    uint32_t y;         // The y coordinate of the mouse
    uint16_t keycode;   // The keycode for the key that was last pressed
    uint64_t timestamp; // When the event was passed (JS timestamp)
    uint8_t flags;      // 0 0 0 0 0 0 MOUSE_DOWN
};

// Where all of the events will be passed
extern js_event *event_location;

// Get the X position of the mouse on the screen
inline uint32_t get_mouse_x() {
    return event_location->x;
}

// Get the Y position of the mouse on the screen
inline uint32_t get_mouse_y() {
    return event_location->y;
}

// Get the mouse position as a vector
inline Vector2<int> get_mouse() {
    return Vector2<int>(get_mouse_x(), get_mouse_y());
}

// Get the current keycode
inline uint16_t get_keycode() {
    return event_location->keycode;
}

// Get timestamp in miliseconds
inline uint64_t get_timestamp() {
    return event_location->timestamp;
}

// Get timestamp in seconds (sti)
inline double get_timestamp_s() {
    return event_location->timestamp / 1000;
}

// Is the mouse down?
inline bool mouse_down() {
    return event_location->flags & 0b00000001;
}

extern "C" {
    // Get the location in memory where events will be passed
    EMSCRIPTEN_KEEPALIVE js_event* get_event_location();
}
