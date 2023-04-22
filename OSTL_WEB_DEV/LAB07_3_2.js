var c = document.getElementById("canvas-club");
Var CTX = C.getContext("2d"); //Get the canvas context
var w = c.width = window.innerWidth;
Var H = C.height = window.innerHeight; // Set the width and height of canvas
Var clearColor = 'rgba (0, 0, 0,.1)'; // Sketchpad background, note that the final transparency of 0.1 is the basis for the superposition effect.

function random(min, max) {
    return Math.random() * (max - min) + min;
}

function Rippling() {}
// Ripple Object This is the main part of Ripple Animation
Rippling.prototype = {
    init: function() {
        This.x = random(0, w); //Ripple x coordinates
        This.y = random(h * .8, h * .9); //Ripple y coordinates
        This.w = 2; //elliptical ripple width
        This.h = 1; // Elliptical Ripple Height
        This.vw = 3; // Width Growth Rate
        This.vh = 1; // Height Growth Rate
        This.a = 1; // Transparency
        This.VA = 96; // Gradual Variation of Ripple Disappearance
    },
    draw: function() {
        ctx.beginPath();
        ctx.moveTo(this.x, this.y - this.h / 2);
        // Draw the right arc
        ctx.bezierCurveTo(
            this.x + this.w / 2, this.y - this.h / 2,
            this.x + this.w / 2, this.y + this.h / 2,
            this.x, this.y + this.h / 2);
        // Draw a left arc
        ctx.bezierCurveTo(
            this.x - this.w / 2, this.y + this.h / 2,
            this.x - this.w / 2, this.y - this.h / 2,
            this.x, this.y - this.h / 2);

        ctx.strokeStyle = 'hsla(180, 100%, 50%, ' + this.a + ')';
        ctx.stroke();
        ctx.closePath();
        This.update(); // Update coordinates
    },
    update: function() {
        if (this.a > .03) {
            This.w += this.vw; //width growth
            This.h += this.vh; //high growth
            if (this.w > 100) {
                This.a *= this.va; // When the width exceeds 100, the ripples fade away gradually.
                This.vw *= .98; //Width Increase Slowly
                This.vh *= .98; //height growth slows down
            }
        } else {
            this.init();
        }

    }
};

function resize() {
    w = c.width = window.innerWidth;
    h = c.height = window.innerHeight;
}

// Initialize a ripple
var r = new Rippling();
r.init();

function anim() {
    ctx.fillStyle = clearColor;
    ctx.fillRect(0, 0, w, h);
    r.draw();
    requestAnimationFrame(anim);
}

window.addEventListener("resize", resize);
// Start animation
anim();