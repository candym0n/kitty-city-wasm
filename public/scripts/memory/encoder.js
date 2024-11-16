import MemoryManager from "./memoryManager.js";

export default class Encoder {
    // The text decoder
    static textDecoder = new TextDecoder("utf-8");

    // Decode a string given pointer to first byte
    static decodeString(pointer) {
        // The bytes starting at the pointer
        let bytes = new Uint8Array(MemoryManager.memory.buffer, pointer);

        // Calculate the length of the (null terminated) string
        let strlen = 0;
        while (bytes[strlen]) ++strlen;

        // Decode it using the text decoder
        return this.textDecoder.decode(bytes.slice(0, strlen));
    }
}
