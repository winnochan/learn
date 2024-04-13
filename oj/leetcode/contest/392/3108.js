/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[][]} query
 * @return {number[]}
 */
var minimumCost = function (n, edges, query) {
  let ansList = [];

  let uf = new UF(n);
  let graph = new Map();
  for (const e of edges) {
    let [u, v, w] = e;
    if (!graph.has(u)) {
      graph.set(u, []);
    }
    if (!graph.has(v)) {
      graph.set(v, []);
    }
    graph.get(u).push([v, w]);
    graph.get(v).push([u, w]);
    uf.union(u, v);
  }
  // console.log(graph);
  // console.log(uf.ids);
  let map = new Map();
  for (const [s, t] of query) {
    let ans = -1;
    if (!uf.isSameSet(s, t)) {
      ansList.push(ans);
      continue;
    } else {
      ansList.push(bfs(graph, s, map));
    }
  }

  return ansList;
};

function bfs(graph, s, map) {
  if (map.has(s)) {
    return map.get(s);
  }
  let ans = -1;
  let vs = new Set([s]);
  let q = [s];
  while (q.length) {
    let u = q.pop();
    let edges = graph.get(u);
    if (!edges) continue;

    for (const [v, w] of edges) {
      ans &= w;
      if (!vs.has(v)) {
        vs.add(v);
        q.push(v);
      }
    }
  }
  for (const v of vs) {
    map.set(v, ans);
  }
  return ans;
}

class UF {
  constructor(n) {
    this.ids = new Array(n).fill(0).map((_, i) => i);
  }

  union(j, k) {
    this.ids[this.find(j)] = this.find(k);
  }

  find(i) {
    if (this.ids[i] !== i) {
      this.ids[i] = this.find(this.ids[i]);
    }
    return this.ids[i];
  }

  isSameSet(j, k) {
    return this.find(j) === this.find(k);
  }
}

console.log(
  minimumCost(
    5,
    [
      [0, 1, 7],
      [1, 3, 7],
      [1, 2, 1],
    ],
    [
      [0, 3],
      [3, 4],
    ],
  ),
);
