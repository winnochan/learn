/**
 * @param {number[][]} points
 * @param {number} w
 * @return {number}
 */
var minRectanglesToCoverPoints = function (points, w) {
  let xs = Array.from(new Set(points.map((p) => p[0]))).sort((a, b) => a - b);
  if (!w) return xs.length;
  let prev = 0;

  let ans = 0;
  for (let i = 0; i < xs.length; i++) {
    if (xs[i] - xs[prev] <= w) {
      continue;
    }
    ans++;
    prev = i;
  }
  if (prev < xs.length) {
    ans++;
  }

  return ans;
};

console.log(
  minRectanglesToCoverPoints(
    [
      [2, 1],
      [1, 0],
      [1, 4],
      [1, 8],
      [3, 5],
      [4, 6],
    ],
    1,
  ),
);

console.log(
  minRectanglesToCoverPoints(
    [
      [0, 0],
      [1, 1],
      [2, 2],
      [3, 3],
      [4, 4],
      [5, 5],
      [6, 6],
    ],
    2,
  ),
);

console.log(
  minRectanglesToCoverPoints(
    [
      [2, 3],
      [1, 2],
    ],
    0,
  ),
);
