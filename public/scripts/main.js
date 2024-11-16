import Wasm from "./wasm.js";
import JSEvent from "./events/events.js";
import Graphics from "./graphics.js"
import EventHandler from "./events/eventHandler.js";
import AudioManager from "./media/audio.js";
import ImageManager from "./media/image.js";
import BackgroundMusic from "./media/background.js";

// Entry point for execution
async function main() {
    try {
        // Initialize Web Assembly
        await Wasm.Init("wasm/game.wasm", {
            ...Graphics.exported,
            ...AudioManager.exported,
            ...ImageManager.exported,
            ...AudioManager.exported,
            ...BackgroundMusic.exported
        });
        
        // Initialize stuff
        Graphics.Init();
        JSEvent.Init();
        EventHandler.Init();
        AudioManager.Init();
        ImageManager.Init();
        AudioManager.Init();

        // Call the main function
        Wasm.exports.main();

        // Start the game loop!
        update();
    } catch (err) {
        document.body.innerHTML = `
        <h1>Error!</h1>
        <hr />
        <code style="color:#aa0000">${err.toString()}</code>
        `
    }
}

// Called once per frame
function update() {
    requestAnimationFrame(update);

    // Update STUFF
    EventHandler.Update();
    AudioManager.UpdateAudio();
    BackgroundMusic.Update();

    // Call the Web Assembly update function
    Wasm.exports.update();
}

// Call the entry point
main();
