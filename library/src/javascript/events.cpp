#include <javascript/events.h>

struct js_event* event_location;

extern "C" js_event* get_event_location() {
    // Allocate some block of memory for events
    event_location = static_cast<js_event*>(malloc(sizeof(js_event)));
    return event_location;
}
