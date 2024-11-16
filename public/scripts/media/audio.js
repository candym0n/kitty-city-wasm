import Encoder from "../memory/encoder.js"
import StructFormat from "../memory/structformat.js";
import Wasm from "../wasm.js";
import BackgroundMusic from "./background.js";

export default class AudioManager {
    // uint32_t int id -> Audio audio
    static mapping = new Map();

    // The number of audios that are loaded
    // Get it?
    static AUTO_INCREMENT = 1;

    // The things loaded
    static loaded = 0;

    // The struct for js_event
    static format = new StructFormat({
        "numAudio": "unsigned int",
        "loaded": "unsigned int",
        "flags": "unsigned char"
    });

    // The pointer to where the audio information is
    static pointer = null;

    // Initialize the audio
    static Init() {
        this.pointer = Wasm.exports.get_audio_location();
    }

    // Register an audio file
    static RegisterAudio(ptr) {
        // Calculuate the path
        const path = Encoder.decodeString(ptr);
        
        // Set the audio
        this.mapping.set(this.AUTO_INCREMENT, new Audio("audio/" + path));

        // Add an event listener
        this.mapping.get(this.AUTO_INCREMENT).addEventListener("canplaythrough", () => {
            ++AudioManager.loaded;
            AudioManager.UpdateAudio();
        });

        // Update the audio struct
        AudioManager.UpdateAudio();

        return this.AUTO_INCREMENT++;
    }

    // Play an audio file
    static PlayAudio(id) {
        this.mapping.get(id).currentTime = 0;
        this.mapping.get(id).play();
    }

    // Get the exported functions
    static get exported() {
        return {
            RegisterAudio: this.RegisterAudio.bind(this),
            PlayAudio: this.PlayAudio.bind(this)
        };
    }

    // Update the structure
    static UpdateAudio() {
        this.format.writeValues({
            "numAudio": this.mapping.entries.length,
            "loaded": this.loaded,
            "flags": !BackgroundMusic.paused
        }, this.pointer);
    }
}
