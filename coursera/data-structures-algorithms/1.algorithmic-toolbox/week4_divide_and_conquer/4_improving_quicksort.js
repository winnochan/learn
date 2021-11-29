const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");
rl.once("line", () => {
  rl.once("line", (line) => {
    const arr = line
      .toString()
      .split(" ")
      .map((s) => +s.trim());

    // console.log(arr.slice(0).sort((a, b) => a - b));
    console.log(quickSort3Way(arr));
    process.exit();
  });
});

function shuffle(arr = []) {
  for (let i = arr.length - 1; i >= 0; i--) {
    const j = Math.floor((i + 1) * Math.random());
    if (i != j) {
      const t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
  }
  return arr;
}

function partition(arr = [], l, r) {
  //
}

function quickSort3Way(arr = [], l = 0, r = null) {
  if (r === null) {
    r = arr.length - 1;
    shuffle(arr);
  }
  const [m1, m2] = partition(arr, l, r);
  quickSort3Way(arr, l, m1 - 1);
  quickSort3Way(arr, m2 + 1, r);
  return arr;
}

module.exports = quickSort3Way;
