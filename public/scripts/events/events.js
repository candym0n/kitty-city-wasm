import StructFormat from "../memory/structformat.js"
import Wasm from "../wasm.js";

export default class JSEvent {
    // The format of an event
    static format = new StructFormat({
        "x": "unsigned int",
        "y": "unsigned int",
        "keycode": "unsigned short",
        "timestamp": "unsigned long",
        "flags": "unsigned char"
    });

    // The pointer to where the events will be stored
    static pointer = null;

    // Initialize events
    static Init() {
        // Get the pointer
        this.pointer = Wasm.exports.get_event_location();
    }

    // Write an event
    static writeEvent(values) {
        this.format.writeValues(values, this.pointer);
    }

    // Get the current event
    static get current() {
        return this.format.readStruct(this.pointer);
    }
}
