/* Math */
js.math = function() {
}
js.math.Math = function() {
}

js.math.Math.prototype = new konoha.Object();
js.math.Math.prototype.konohaclass = "js.math.Math";
js.math.Math.sqrt = function(f) {
    return Math.sqrt(f);
}
js.math.Math.cos = function(f) {
    return Math.cos(f);
}
js.math.Math.sin = function(f) {
    return Math.sin(f);
}
js.math.Math.floor = function(f) {
    return Math.floor(f);
}
js.math.Math.abs = function(f) {
    return Math.abs(f);
}
js.math.Math.fabs = function(f) {
    return Math.abs(f);
}
js.math.Math.random = function() {
    return Math.random();
}
js.math.Math.pow = function(a, b) {
    return Math.pow(a, b);
}
js.math.Math.tan = function(f) {
    return Math.tan(f);
}
js.math.Math.toDegrees = function(f) {
	return f * (Math.PI / 180);
}
js.math.Math.toRadians = function(f) {
	return f * (180 / Math.PI);
}
js.math.Math.exp = function(f) {
	return Math.exp(f);
}
js.math.Math.log = function(f) {
	return Math.log(f);
}
js.math.Math.log10 = function(f) {
	return Math.LOG10E * Math.log(f);
}
js.math.Math.getE = function() {
	return Math.E;
}
js.math.Math.getPI = function() {
	return Math.PI;
}
