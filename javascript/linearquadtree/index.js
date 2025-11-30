const N = 4;
const Wd = 10;
const Hd = 10;

class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
}

function key(p) {
    let key = [];
    for (let i = 0; i < N; i++) {
        key.push(
            ((p.x >> Wd-N+i) & 1) |
            ((p.y >> Hd-N+i-1) & 2));
    }
    return key;
}

points = [
    new Point(0, 32),
    new Point(512, 512),
    new Point(900, 32),
    new Point(32, 800),
    new Point(800, 800)
]
for (let point of points) {
    console.log(point, key(point));
}