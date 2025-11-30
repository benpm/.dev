class Point {
    constructor(x, y) {
        this.x = Math.floor(x);
        this.y = Math.floor(y);
    }
}

function dist(p, b, s) {
    const dx = Math.max(Math.abs(px - x) - s.x / 2, 0);
    const dy = Math.max(Math.abs(py - y) - s.y / 2, 0);
    return dx * dx + dy * dy;
}

