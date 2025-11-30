/** Constant time neighbor-finding quadtrees
 * adapted from https://ieeexplore.ieee.org/document/4537278
 */

// Max tree depth
const r = 3;

// Location code mask
const M = parseInt("11".repeat(r), 2);

// Axis masks
const tX = parseInt("01".repeat(r), 2);
const tY = parseInt("10".repeat(r), 2);

// Direction codes
const dirs = [
	parseInt("000001", 2), // E
	parseInt("000011", 2), // NE
	parseInt("000010", 2), // N
	parseInt("010111", 2), // NW
	parseInt("010101", 2), // W
	parseInt("111111", 2), // SW
	parseInt("101010", 2), // S
	parseInt("101011", 2)  // SE
];

/* Quadtree node codes:
		[2][3]
		[0][1]
 */

/** Add direction to quadtree location code
 * loc: quad node location code
 * dir: direction code
 */
function locAdd(loc, dir) {
	return ((loc | tY) + (dir & tX)) & tX | ((loc | tX) + (dir & tY)) & tY;
}

/** Find equal-sized neighbors of quad node
 * loc: quad node location code
 * level: quad node tree depth level
 */
function eqNeighbors(loc, lvl) {
	let neighbors = [];
	for (let i = 0; i < 8; i++) {
		neighbors.push(locAdd(loc, dirs[i] << (2 * (r - lvl))));
	}
	return neighbors;
}

function findNeighbor(tree, loc, lvl, dir) {
	// Level difference between node and neighbor in direction
	const lvlDiff = tree[loc][lvl].lvlDiffs[dir];
	if (lvlDiff != null) {
		if (lvlDiff < 0) {
			// Neighbor is larger than I am
			const xd = r - lvl - lvlDiff;
			return [
				locAdd((loc >> (2 * xd)) << (2 * xd), dirs[lvl] << (2 * xd)),
				lvl + lvlDiff
			];
		} else {
			// Neighbors are smaller or same size, so return their parent
			return [
				locAdd(loc, dirs[lvl] << (2 * (r - lvl)))
			];
		}
	}
}

/** NOTES
 * When inserting points and a split occurs, iterate through neighbors of each newly created node
 * 	and add 1 to their neighbor's level difference which is on shared edge to node
 * */

let x = parseInt("033", 4)
for (let n of eqNeighbors(x, 3)) {
	console.log(n.toString(4))
}