import Wasm from "../wasm.js";
import Encoder from "./encoder.js";
import StructFormat from "./structformat.js";

export default class MemoryManager {
    static decoder = new TextDecoder("utf-8");
    
    // The memory to manage
    static memory = new WebAssembly.Memory({
        initial: 256,
        maximum: 512
    });

    // The encoder / decoder
    static encoder = new Encoder(this.memory);

    // Read a single value
    static readValue(type, ptr) {
        let offset = 0;
        let result = 0;

        // Create a DataView for byte stuff.
        let dataView = new DataView(this.memory.buffer);

        switch (type) {
            case "int":
                result = dataView.getInt32(ptr, true);
                offset = StructFormat.types.int;
                break;
        
            case "unsigned int":
                result = dataView.getUint32(ptr, true);
                offset = StructFormat.types.unsignedInt;
                break;
        
            case "short":
                result = dataView.getInt16(ptr, true);
                offset = StructFormat.types.short;
                break;
        
            case "unsigned short":
                result = dataView.getUint16(ptr, true);
                offset = StructFormat.types.unsignedShort;
                break;
        
            case "char":
                result = dataView.getInt8(ptr);
                offset = StructFormat.types.char;
                break;
        
            case "unsigned char":
                result = dataView.getUint8(ptr);
                offset = StructFormat.types.unsignedChar;
                break;
        
            case "long":
                result = dataView.getBigInt64(ptr, true);
                offset = StructFormat.types.long;
                break;
        
            case "unsigned long":
                result = dataView.getBigUint64(ptr, true);
                offset = StructFormat.types.unsignedLong;
                break;
        
            case "float":
                result = dataView.getFloat32(ptr, true);
                offset = StructFormat.types.float;
                break;
        
            case "double":
                result = dataView.getFloat64(ptr, true);
                offset = StructFormat.types.double;
                break;
        
            default:
                throw new Error(`Unsupported type: ${type}`);
        }

        return { offset, result };
    }

    // Write a single value
    static writeValue(type, value, ptr) {
        let offset = 0;
        let dataView = new DataView(this.memory.buffer);

        switch (type) {
            case "int":
                dataView.setInt32(ptr, value, true);
                offset = StructFormat.types.int;
                break;
        
            case "unsigned short":
                dataView.setUint16(ptr, value, true);
                offset = StructFormat.types.unsignedShort;
                break;
        
            case "short":
                dataView.setInt16(ptr, value, true);
                offset = StructFormat.types.short;
                break;
        
            case "unsigned int":
                dataView.setUint32(ptr, value, true);
                offset = StructFormat.types.unsignedInt;
                break;
        
            case "char":
                dataView.setInt8(ptr, value);
                offset = StructFormat.types.char;
                break;
        
            case "unsigned char":
                dataView.setUint8(ptr, value);
                offset = StructFormat.types.unsignedChar;
                break;
        
            case "long":
                dataView.setBigInt64(ptr, BigInt(value), true);
                offset = StructFormat.types.long;
                break;
        
            case "unsigned long":
                dataView.setBigUint64(ptr, BigInt(value), true);
                offset = StructFormat.types.unsignedLong;
                break;
        
            case "float":
                dataView.setFloat32(ptr, value, true);
                offset = StructFormat.types.float;
                break;
        
            case "double":
                dataView.setFloat64(ptr, value, true);
                offset = StructFormat.types.double;
                break;
        
            default:
                throw new Error(`Unsupported type: ${type}`);
        }
        return offset;
    }

    // An implementation of memcpy
    static memcpy(dest, src, num) {
        const memory = Wasm.exports.HEAP8;
        const sourceView = new Uint8Array(memory.buffer, src, num);
        const destView = new Uint8Array(memory.buffer, dest, num);
        destView.set(sourceView);
        return dest;
    }
}
