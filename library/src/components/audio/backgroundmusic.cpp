#include <components/audio/backgroundmusic.h>

bool BackgroundMusic::isPlaying = false;

void BackgroundMusic::Play() {
    play_background_music();
    isPlaying = true;
}

void BackgroundMusic::Pause() {
    pause_background_music();
    isPlaying = false;
}

void BackgroundMusic::NextSong() {
    next_song();
}

void BackgroundMusic::Toggle() {
    if (isPlaying) {
        Pause();
    }  else {
        Play();
    }
}

// Called once per frame
void BackgroundMusic::Update() {
    // Re-sync it
    if (isPlaying && !is_playing()) play_background_music();
    if (!isPlaying && is_playing()) pause_background_music();
}
