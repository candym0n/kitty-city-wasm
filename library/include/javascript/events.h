#pragma once

#include <stdint.h>
#include <emscripten.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Get info about the current event
inline uint32_t get_mouse_x() {
    return event_location->x;
}

inline uint32_t get_mouse_y() {
    return event_location->y;
}

inline uint16_t get_keycode() {
    return event_location->keycode;
}

inline uint64_t get_timestamp() {
    return event_location->timestamp;
}

inline bool mouse_down() {
    return event_location->flags & 0b00000001;
}

extern "C" {
    // Get the location in memory where events will be passed
    EMSCRIPTEN_KEEPALIVE js_event* get_event_location();
}
