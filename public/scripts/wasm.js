"use strict";

import MemoryManager from "./memory/memoryManager.js";
import Encoder from "./memory/encoder.js";

export default class Wasm {
    static exports;

    // Start streaming a Wasm file
    static async Init(file, functions) {
        // Get the binary Wasm file
        const response = await fetch(file);

        // Start streaming it
        const { instance } = await WebAssembly.instantiateStreaming(response, {
            js: {
                mem: MemoryManager.memory
            },
            env: {
                emscripten_resize_heap: MemoryManager.memory.grow,
                _emscripten_memcpy_js: MemoryManager.memcpy,
                _abort_js: printString,
                __cxa_throw: printString,
                emscripten_get_now: Date.now,
                getentropy,
                printString,
                ...functions
            }
        });
        // Set corresponding items
        this.exports = instance.exports;
        MemoryManager.memory = this.exports.memory;
    }
}

// Printing
function printString(pointer) {
    console.log(Encoder.decodeString(pointer));
}

// Get a random number
function getentropy(bufferPtr, length) {
    // Create a temporary array to hold the random values
    const tempArray = new Uint8Array(length);
    crypto.getRandomValues(tempArray);
    
    // Copy random values into the WASM memory buffer
    for (let i = 0; i < length; i++) {
      new Uint8Array(MemoryManager.memory.buffer, bufferPtr + i)[0] = tempArray[i];
    }
    
    return 0; // 0 on success, non-zero on failure
  }
