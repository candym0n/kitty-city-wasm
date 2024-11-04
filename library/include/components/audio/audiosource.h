#pragma once

#include <game.h>
#include <media.h>

// For sound effects; use BackgroundMusic for music
class AudioSource : public Component {
private:
    // The sound effect to play
    audio_t audio;
    
public:
    AudioSource() : audio(0) {}

    // Set the audio to play
    void SetAudio(const char* path) {
        audio = register_audio(path);
    }

    // Set the audio to play
    void SetAudio(audio_t id) {
        audio = id;
    }

    // Play the audio once
    void Play() {
        if (audio) {
            play_audio(audio);
        }
    }
};
