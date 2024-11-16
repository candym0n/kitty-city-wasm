#include <media/audio.h>

// Imported JavaScript functions
EM_JS(static audio_t, RegisterAudio, (const char *path), {})
EM_JS(static void, PlayAudio, (audio_t id), {})
EM_JS(static void, PlayBackgroundMusic, (void), {})
EM_JS(static void, PauseBackgroundMusic, (void), {})
EM_JS(static void, NextSong, (void), {})

struct js_audio* audio_location;

audio_t register_audio(const char *path) {
    return RegisterAudio(path);
}

void play_audio(audio_t audio) {
    PlayAudio(audio);
}

extern "C" js_audio* get_audio_location() {
    // Allocate some block of memory for events
    audio_location = static_cast<struct js_audio*>(malloc(sizeof(struct js_audio)));
    return audio_location;
}

void play_background_music() {
    PlayBackgroundMusic();
}
void pause_background_music() {
    PauseBackgroundMusic();
}
void next_song() {
    NextSong();
}
