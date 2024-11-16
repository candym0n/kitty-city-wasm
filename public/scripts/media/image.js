import Encoder from "../memory/encoder.js"
import StructFormat from "../memory/structformat.js";
import Wasm from "../wasm.js";

export default class ImageManager {
    // uint32_t int id -> Image image
    static mapping = new Map();

    // The number of images that are loaded
    // Get it?
    static AUTO_INCREMENT = 1;

    // The things loaded
    static loaded = 0;

    // The struct for js_event
    static format = new StructFormat({
        "numImage": "unsigned int",
        "loaded": "unsigned int"
    });

    // The pointer to where the image information is
    static pointer = null;

    // Initialize the image
    static Init() {
        this.pointer = Wasm.exports.get_image_location();
    }

    // Register an image file
    static RegisterImage(ptr) {
        // Calculuate the path
        const path = Encoder.decodeString(ptr);
        
        // Set the image
        const image = new Image();
        image.src = "images/" + path;
        this.mapping.set(this.AUTO_INCREMENT, image);

        // Add an event listener
        image.addEventListener("load", () => {
            ++ImageManager.loaded;
            ImageManager.UpdateImage();
        });

        // Update the image struct
        ImageManager.UpdateImage();

        return this.AUTO_INCREMENT++;
    }

    // Get the exported functions
    static get exported() {
        return {
            RegisterImage: this.RegisterImage.bind(this),
        };
    }

    // Update the structure
    static UpdateImage() {
        this.format.writeValues({
            "numImage": this.mapping.size,
            "loaded": this.loaded
        }, this.pointer);
    }
}
