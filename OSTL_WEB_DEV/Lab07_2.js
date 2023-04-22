var g;
var d = new Date();
var h = d.getHours();
var m = d.getMinutes();
var s = d.getSeconds();
var ms = d.getMilliseconds();
if (ms < 10) {
    ms = "0" + ms;
}
if (s < 10) {
    s = "0" + s;
}
if (m < 10) {
    m = "0" + m;
}
if (h < 10) {
    h = "0" + h;
}
if (h < 12) {
    g = " A Very Good Morning Sir !! ";
} else if (h < 18) {
    g = " Good AfterNoon Sir !!  ";
} else {
    g = " Good Night ! <br> Sweet Dreams !! ";
}
document.write("<h2>" + "<font color='purple'>" + g + "</font>" + " <br><br>Welcome to the our prestigious University !<br><br>Hope All your Queries will be Solved . ");
document.write("<br><br>" + h + " : " + m + " : " + s + " : " + ms);