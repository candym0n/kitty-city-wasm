import JSEvent from "./events.js";

export default class EventHandler {
    // The position of the mouse
    static mouseX = 0;
    static mouseY = 0;

    // The keycode
    static keycode = 0;

    // Some flags
    static mouseDown = 0;

    // Setup the events
    static Init() {
        document.addEventListener('keydown', ((e) => {
            let code;
            
            // Handle letter keys
            if (e.code.startsWith('Key')) {
                code = e.code.charAt(e.code.length - 1).charCodeAt(0);
            }
            // Handle digit keys
            else if (e.code.startsWith('Digit')) {
                code = Number(e.code.charAt(e.code.length - 1)) + 48;
            }
            // Handle numpad
            else if (e.code.startsWith('Numpad')) {
                switch (e.code) {
                    case 'Numpad0': code = 96; break;
                    case 'Numpad1': code = 97; break;
                    case 'Numpad2': code = 98; break;
                    case 'Numpad3': code = 99; break;
                    case 'Numpad4': code = 100; break;
                    case 'Numpad5': code = 101; break;
                    case 'Numpad6': code = 102; break;
                    case 'Numpad7': code = 103; break;
                    case 'Numpad8': code = 104; break;
                    case 'Numpad9': code = 105; break;
                    case 'NumpadMultiply': code = 106; break;
                    case 'NumpadAdd': code = 107; break;
                    case 'NumpadSubtract': code = 109; break;
                    case 'NumpadDecimal': code = 110; break;
                    case 'NumpadDivide': code = 111; break;
                }
            }
            // Handle function keys
            else if (e.code.startsWith('F') && !isNaN(e.code.substring(1))) {
                const fNum = parseInt(e.code.substring(1));
                if (fNum >= 1 && fNum <= 12) {
                    code = 111 + fNum;
                }
            }
            // Handle all other special keys
            else {
                switch (e.code) {
                    // Special Characters
                    case 'Semicolon': code = 186; break;
                    case 'Equal': code = 187; break;
                    case 'Comma': code = 188; break;
                    case 'Minus': code = 189; break;
                    case 'Period': code = 190; break;
                    case 'Slash': code = 191; break;
                    case 'Backquote': code = 192; break;
                    case 'BracketLeft': code = 219; break;
                    case 'Backslash': code = 220; break;
                    case 'BracketRight': code = 221; break;
                    case 'Quote': code = 222; break;
        
                    // Control Keys
                    case 'Backspace': code = 8; break;
                    case 'Tab': code = 9; break;
                    case 'Enter': code = 13; break;
                    case 'ShiftLeft': code = 16; break;
                    case 'ControlLeft': code = 17; break;
                    case 'AltLeft': code = 18; break;
                    case 'Pause': code = 19; break;
                    case 'CapsLock': code = 20; break;
                    case 'Escape': code = 27; break;
                    case 'Space': code = 32; break;
                    case 'PageUp': code = 33; break;
                    case 'PageDown': code = 34; break;
                    case 'End': code = 35; break;
                    case 'Home': code = 36; break;
                    case 'ArrowLeft': code = 37; break;
                    case 'ArrowUp': code = 38; break;
                    case 'ArrowRight': code = 39; break;
                    case 'ArrowDown': code = 40; break;
                    case 'Insert': code = 45; break;
                    case 'Delete': code = 46; break;
                    case 'MetaLeft': code = 91; break; // Windows key
                    case 'MetaRight': code = 92; break;
                    case 'ContextMenu': code = 93; break;
                    case 'PrintScreen': code = 44; break;
                    case 'ScrollLock': code = 145; break;
                    case 'NumLock': code = 144; break;
        
                    // Media Keys
                    case 'AudioVolumeMute': code = 173; break;
                    case 'AudioVolumeDown': code = 174; break;
                    case 'AudioVolumeUp': code = 175; break;
                    case 'MediaTrackNext': code = 176; break;
                    case 'MediaTrackPrevious': code = 177; break;
                    case 'MediaStop': code = 178; break;
                    case 'MediaPlayPause': code = 179; break;
        
                    // Browser Keys
                    case 'BrowserBack': code = 166; break;
                    case 'BrowserForward': code = 167; break;
                    case 'BrowserRefresh': code = 168; break;
                    case 'BrowserStop': code = 169; break;
                    case 'BrowserSearch': code = 170; break;
                    case 'BrowserFavorites': code = 171; break;
                    case 'BrowserHome': code = 172; break;
        
                    // Modifier States
                    case 'ShiftLeft': code = 160; break;
                    case 'ShiftRight': code = 161; break;
                    case 'ControlLeft': code = 162; break;
                    case 'ControlRight': code = 163; break;
                    case 'AltLeft': code = 164; break;
                    case 'AltRight': code = 165; break;
                }
            }
        
            // Ensure 16-bit integer
            code = code & 0xFFFF;
            
            this.keycode = code;
        }).bind(this));

        document.addEventListener("keyup", (function(e) {
            this.keycode = 0;
        }).bind(this));

        document.addEventListener("mousemove", (function(e) {
            this.mouseX = e.clientX;
            this.mouseY = e.clientY;
        }).bind(this));

        document.addEventListener("mousedown", (function(e) {
            this.mouseDown = true;
        }).bind(this));

        document.addEventListener("mouseup", (function(e) {
            this.mouseDown = false;
        }).bind(this));
    }

    // Update the events
    static Update() {
        JSEvent.writeEvent({
            "x": this.mouseX,
            "y": this.mouseY,
            "keycode": this.keycode,
            "timestamp": Date.now(),
            "flags": this.mouseDown
        });
    }
}
