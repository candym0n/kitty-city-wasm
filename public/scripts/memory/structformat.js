import MemoryManager from "./memoryManager.js";

export default class StructFormat {
    // The sizes of different C++ types
    static types = {
        char: 1,
        short: 2,
        int: 4,
        float: 4,
        double: 8,
        long: 8,
        unsignedInt: 4,
        unsignedChar: 1,
        unsignedLong: 8,
        unsignedShort: 2
    }

    // Create a new struct format
    constructor(format) {
        this.format = format;
    }

    // Get the size of a struct format
    get size() {
        let size = 0;

        for (const type of Object.values(this.format)) {
            size += StructFormat.types[type];
        }

        return size;
    }

    // Allocate a new instance of this into memory
    newInstance(module, values) {
        // Get the new pointer
        const ptr = module.wasmmalloc(this.size);

        // Write the values
        if (values) this.writeValues(values, ptr);

        return ptr;
    }

    // Read a struct from memory
    readStruct(ptr) {
        const res = {};
        let off = 0;  // Track the current memory offset

        for (const key in this.format) {
            const type = this.format[key];
            const { result, offset } = MemoryManager.readValue(type, ptr + off);
            res[key] = result;
            off += offset;
        }

        return res;
    }

    // Write a struct into memory
    writeValues(values, ptr) {
        let offset = 0;

        for (const key in this.format) {
            const type = this.format[key];
            const value = values[key];

            offset += MemoryManager.writeValue(type, value, ptr + offset);
        }
    }
}
