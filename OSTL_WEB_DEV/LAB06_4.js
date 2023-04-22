function drawRectangle() {
    var ctx;
    var canvas = document.getElementById("canvas");
    if (canvas.getContext) {
        ctx = canvas.getContext("2d");
        ctx.font = "11pt Helvetica";

        ctx.strokeStyle = "black";
        ctx.strokeRect(50, 20, 75, 75);
        ctx.fillText("stroke Rectangle", 40, 120);

        ctx.fillStyle = "black";
        ctx.fillRect(200, 20, 75, 75);
        ctx.fillText("Fill Rectangle", 190, 120);
    }
}

function drawCircle() {
    var ctx;
    var canvas = document.getElementById("canvas");
    if (canvas.getContext) {
        ctx = canvas.getContext("2d");
        ctx.arc(20, 100, 40, 0, Math.PI * 3 / 2, true);
        ctx.stroke();

        ctx.beginPath();
        ctx.arc(120, 100, 40, 0, Math.PI, true);
        ctx.stroke();

        ctx.beginPath();
        ctx.arc(220, 100, 40, 0, Math.PI / 2, true);
        ctx.stroke();

        ctx.beginPath();
        ctx.arc(320, 100, 40, 0, Math.PI * 2, true);
        ctx.stroke();

        ctx.fillStyle = "black";
        ctx.beginPath();
        ctx.arc(20, 200, 40, 0, Math.PI * 3 / 2, true);
        ctx.fill();

        ctx.beginPath();
        ctx.arc(120, 200, 40, 0, Math.PI, true);
        ctx.fill();

        ctx.beginPath();
        ctx.arc(220, 200, 40, 0, Math.PI / 2, true);
        ctx.fill();

        ctx.beginPath();
        ctx.arc(320, 200, 40, 0, Math.PI * 2, true);
        ctx.fill();
    }
}