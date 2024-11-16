#pragma once

#include <emscripten.h>
#include <stdint.h>

// The struct for passing information about audio
struct js_audio {
    uint32_t numAudio;  // The number of audio things
    uint32_t loaded;    // The number of audio things loaded
    uint8_t flags;      // 0 0 0 0 0 0 0 isPlaying
};

// An audio ID
typedef uint32_t audio_t;

// Register an audio
audio_t register_audio(const char *path);

// Play a sound
void play_audio(audio_t audio);

// Background music
void play_background_music();
void pause_background_music();
void next_song();

// Where audio information is stored
extern struct js_audio *audio_location;

// Get information about audio
inline uint32_t get_total_audio() {
    return audio_location->numAudio;
}

inline uint32_t get_loaded_audio() {
    return audio_location->loaded;
}

inline bool is_playing() {
    return audio_location->flags & 0b00000001;
}

extern "C" {
    // Get the location in memory where events will be passed
    EMSCRIPTEN_KEEPALIVE js_audio* get_audio_location();
}
