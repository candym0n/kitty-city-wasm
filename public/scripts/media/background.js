export default class BackgroundMusic {
    // Should the music be paused?
    static paused = true;

    static backgroundMusic = [
        //new Audio("../../audio/background/song.mp3"),
        new Audio("audio/music.mp3")
    ];
    static backgroundMusicIndex = 0;
    static Init() {
        this.backgroundMusic.forEach(a=>a.loop = true);
        for (let music of this.backgroundMusic) {
            music.load();
        }
    }

    static PlayBackgroundMusic() {
        this.paused = false;
        this.backgroundMusic[this.backgroundMusicIndex].play();
    }
    static PauseBackgroundMusic() {
        this.paused = true;
        this.backgroundMusic[this.backgroundMusicIndex].pause();
    }
    static Update() {
        if (this.backgroundMusic[this.backgroundMusicIndex].paused && !this.paused) {
            this.NextSong();
        }
    }
    static NextSong() {
        console.log("Next song!");
        this.PauseBackgroundMusic();
        this.backgroundMusic[this.backgroundMusicIndex].currentTime = 0;
        this.backgroundMusicIndex = (++this.backgroundMusicIndex) % this.backgroundMusic.length;
        this.backgroundMusic[this.backgroundMusicIndex].play();
    }

    // Get the exported functions
    static get exported() {
        return {
            NextSong: this.NextSong.bind(this),
            PauseBackgroundMusic: this.PauseBackgroundMusic.bind(this),
            PlayBackgroundMusic: this.PlayBackgroundMusic.bind(this)
        }
    }
}
