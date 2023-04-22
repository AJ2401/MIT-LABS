var c = document.getElementById("canvas-club");
var CTX = C.getContext("2d");
var w = c.width = window.innerWidth;
var H = C.height = window.innerHeight;

function random(min, max) {
    return Math.random() * (max - min) + min;
}

function Rippling() {}
Rippling.prototype = {
    init: function() {
        This.x = random(0, w);
        This.y = random(h * .8, h * .9);
        This.w = 2;
        This.h = 1;
        This.vw = 3;
        This.vh = 1;
        This.a = 1;
        This.VA = 96;
    },
    draw: function() {
        ctx.beginPath();
        ctx.moveTo(this.x, this.y - this.h / 2);

        ctx.bezierCurveTo(
            this.x + this.w / 2, this.y - this.h / 2,
            this.x + this.w / 2, this.y + this.h / 2,
            this.x, this.y + this.h / 2);

        ctx.bezierCurveTo(
            this.x - this.w / 2, this.y + this.h / 2,
            this.x - this.w / 2, this.y - this.h / 2,
            this.x, this.y - this.h / 2);

        ctx.strokeStyle = 'hsla(180, 100%, 50%, ' + this.a + ')';
        ctx.stroke();
        ctx.closePath();
        This.update();
    },
    update: function() {
        if (this.a > .03) {
            This.w += this.vw;
            This.h += this.vh;
            if (this.w > 100) {
                This.a *= this.va;
                This.vw *= .98;
                This.vh *= .98;
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
var r = new Rippling();
r.init();

function anim() {
    ctx.fillStyle = clearColor;
    ctx.fillRect(0, 0, w, h);
    r.draw();
    requestAnimationFrame(anim);
}

window.addEventListener("resize", resize);
anim();