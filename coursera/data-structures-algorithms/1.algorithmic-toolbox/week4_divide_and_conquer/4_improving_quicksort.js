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

    // console.log(arr.slice(0).sort((a, b) => a - b));
    console.log(quickSort3Way(arr).map(String).join(" "));
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

function swap(arr = [], j, k) {
  [arr[j], arr[k]] = [arr[k], arr[j]];
}

// 2,3,4,2,5,9,7,2
// 2 4 3 2 5 9 7 2
// 2 2 3 2 5 9 7 4
function partition(arr = [], left, right) {
  const val = arr[left];
  let mid = left;
  while (mid <= right) {
    if (arr[mid] === val) {
      mid++;
    } else if (arr[mid] > val) {
      swap(arr, mid, right--);
    } else {
      swap(arr, mid, left++);
    }
  }
  return [left, right];
}

function quickSort3Way(arr = [], l = 0, r = null) {
  if (r === null) {
    r = arr.length - 1;
    shuffle(arr);
    // console.log("shuffle", arr);
  }
  const [m1, m2] = partition(arr, l, r);
  if (l < m1 - 1) {
    quickSort3Way(arr, l, m1 - 1);
  }
  if (m2 + 1 < r) {
    quickSort3Way(arr, m2 + 1, r);
  }
  return arr;
}

module.exports = quickSort3Way;
