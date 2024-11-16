#include <components/audio/audiosource.h>

void AudioSource::SetAudio(const char* path) {
    audio = register_audio(path);
}

void AudioSource::SetAudio(audio_t id) {
    audio = id;
}

void AudioSource::Play() {
    if (audio) {
        play_audio(audio);
    }
}
