var array = [1, 2, 3, 4];

array.splice(4, 0, 5);

console.log(array);

Number.prototype.clamp = function (min, max) {
	return Math.min(max, Math.max(this, min));
};
Array.prototype.interpose = function(objects, value, max, interval=1) {
	this.splice(Math.round(this.length * (value / max)).clamp(0, this.length), 0, ...objects);
};

array.interpose([6, 7, 8], 0.5, 1.0);

console.log(array);
