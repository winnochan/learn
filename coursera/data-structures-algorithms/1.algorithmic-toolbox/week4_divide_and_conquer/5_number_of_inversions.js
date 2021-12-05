const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

// console.log(quickSort3Way([2, 4, 2, 3, 9, 7, 2, 5]));

process.stdin.setEncoding("utf8");
rl.once("line", () => {
  rl.once("line", (line) => {
    const arr = line
      .toString()
      .split(" ")
      .map((s) => +s.trim());

    console.log(numberOfInversions(arr));
    process.exit();
  });
});

function merge(a = [], b = []) {
  const arr = [];
  let n = 0;
  let ai = 0;
  let bi = 0;
  while (ai < a.length || bi < b.length) {
    if (ai === a.length) arr.push(b[bi++]);
    else if (bi === b.length) arr.push(a[ai++]);
    else if (arr[ai] <= arr[bi]) arr.push(a[ai++]);
    else {
      arr.push(b[bi++]);
      n++;
    }
  }
  return [arr, n];
}

function numberOfInversions(arr = []) {
  if (arr.length <= 1) return [arr, 0];
  const mid = Math.floor(arr.length / 2);
  const [l, ln] = numberOfInversions(arr.slice(0, mid));
  const [r, rn] = numberOfInversions(arr.slice(mid));
  const [m, mn] = merge(l, r);
  return [m, ln + rn + mn];
}

module.exports = numberOfInversions;
