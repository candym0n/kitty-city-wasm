"use strict";

import ImageManager from "./media/image.js";

export default class Graphics {
    // The canvas that is used for all graphics
    static canvas = document.querySelector("#canvas");
    static c = this.canvas.getContext("2d");

    // Init the graphics
    static Init() {
        // Resize the canvas
        this.canvas.width = 1600;
        this.canvas.height = 900;

        // Disable antialiasing
        this.c.imageSmoothingEnabled = false;
    }

    // Clear a rectangle (canvas dimensions if width / height is 0)
    static ClearRect(x, y, width, height) {
        this.c.clearRect(x, y, !!width?width:this.canvas.width, !!height?height:this.canvas.height);
    }

    // Draw a rectangle
    static DrawRect(x, y, width, height, color, rotation, opacity) {
        this.c.save();
        this.c.globalAlpha = opacity;
        this.c.translate(x + width / 2, y + height / 2);
        this.c.rotate(rotation * Math.PI / 180);
        this.c.fillStyle = "#" + color.toString(16).padStart(6, 0);
        this.c.fillRect(-width / 2, -height / 2, width, height);
        this.c.restore();
        this.c.globalAlpha = 1;
    }

    // Draw an image
    static DrawImage(x, y, width, height, image, rotation) {
        this.c.save();
        this.c.translate(x + width / 2, y + height / 2);
        this.c.rotate(rotation * Math.PI / 180);
        this.c.drawImage(ImageManager.mapping.get(image), -width / 2, -height / 2, width, height);
        this.c.restore();
    }

    // Get all of the exported functions
    static get exported() {
        return {
            ClearRect: this.ClearRect.bind(this),
            DrawRect: this.DrawRect.bind(this),
            DrawImage: this.DrawImage.bind(this)
        }
    }
}
