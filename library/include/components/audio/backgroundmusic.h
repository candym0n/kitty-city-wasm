#pragma once

#include <game.h>
#include <media.h>

class BackgroundMusic : public Component {
private:
    // Should it play on init?
    bool playOnStart;

    // Should the music be playing?
    bool isPlaying;
public:
    BackgroundMusic() : playOnStart(false) {}

    // Set whether to play the music on init
    void SetPlayOnStart(bool state) {
        playOnStart = state;
    }

    void Init() override {
        if (playOnStart) Play();
    }

    // Play that song!
    void Play() {
        play_background_music();
        isPlaying = true;
    }

    // Pause it
    void Pause() {
        pause_background_music();
        isPlaying = false;
    }

    // Go to the next song
    void NextSong() {
        next_song();
    }

    // Toggle the playing state
    void Toggle() {
        if (isPlaying) {
            Pause();
        }  else {
            Play();
        }
    }

    // Called once per frame
    void Update() override {
        // Re-sync it
        if (isPlaying && !is_playing()) play_background_music();
        if (!isPlaying && is_playing()) pause_background_music();
    }
};
