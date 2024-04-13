/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} disappear
 * @return {number[]}
 */
var minimumTime = function (n, edges, disappear) {
  let ans = new Array(n).fill(-1);

  ans[0] = 0;

  for (let i = 0; i < n; i++) {
    let flag = false;

    for (let [u, v, w] of edges) {
      if (ans[u] >= 0) {
        let val = ans[u] + w;
        if ((ans[v] < 0 || val < ans[v]) && val < disappear[v]) {
          ans[v] = val;
          flag = true;
        }
      }
      [u, v] = [v, u];
      if (ans[u] >= 0) {
        let val = ans[u] + w;
        if ((ans[v] < 0 || val < ans[v]) && val < disappear[v]) {
          ans[v] = val;
          flag = true;
        }
      }
    }

    if (!flag) {
      break;
    }
  }

  return ans;
};

console.log(
  minimumTime(
    3,
    [
      [0, 1, 2],
      [1, 2, 1],
      [0, 2, 4],
    ],
    [1, 1, 5],
  ),
);

console.log(
  minimumTime(
    3,
    [
      [0, 1, 2],
      [1, 2, 1],
      [0, 2, 4],
    ],
    [1, 3, 5],
  ),
);

console.log(minimumTime(2, [[0, 1, 1]], [1, 1]));

console.log(
  minimumTime(
    8,
    [
      [4, 0, 5],
      [3, 7, 3],
      [0, 2, 3],
      [3, 5, 3],
      [7, 0, 1],
      [2, 0, 3],
      [7, 7, 10],
    ],
    [15, 8, 4, 3, 9, 18, 9, 13],
  ),
);
