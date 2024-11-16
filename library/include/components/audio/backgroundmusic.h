#pragma once

#include <game.h>
#include <media.h>

class BackgroundMusic {
private:
    // Should the music be playing?
    static bool isPlaying;
public:
    // Play that song!
    static void Play();

    // Pause it
    static void Pause();

    // Go to the next song
    static void NextSong();

    // Toggle the playing state
    static void Toggle();

    // Called once per frame
    static void Update() ;
};
