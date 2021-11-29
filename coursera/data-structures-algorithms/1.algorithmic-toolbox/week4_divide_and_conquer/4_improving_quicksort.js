const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

console.log(quickSort3Way([2, 3, 9, 2, 2]));

process.stdin.setEncoding("utf8");
rl.once("line", () => {
  rl.once("line", (line) => {
    const arr = line
      .toString()
      .split(" ")
      .map((s) => +s.trim());

    // console.log(arr.slice(0).sort((a, b) => a - b));
    // console.log(quickSort3Way(arr));
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

function partition(arr = [], left, right) {
  const val = arr[left];
  let mid = left;
  let temp;
  while (mid < right) {
    while (mid < right && arr[left] <= val) {
      if (arr[left] == val) {
        mid += 1;
        arr[left] = arr[mid];
        arr[mid] = val;
      } else {
        left++;
      }
    }
    while (mid < right && arr[right] >= val) {
      if (arr[right] == val) {
        mid += 1;
        arr[right] = arr[mid];
        arr[mid] = val;
      } else {
        right--;
      }
    }

    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    console.log(arr, left, right);
  }
  console.log(left, right);
  return [left, right];
}

function quickSort3Way(arr = [], l = 0, r = null) {
  if (r === null) {
    r = arr.length - 1;
    shuffle(arr);
    console.log("shuffle", arr);
  }
  const [m1, m2] = partition(arr, l, r);
  if (l < m1 - 1) {
    quickSort3Way(arr, l, m1 - 1);
  }
  if (m2 < r) {
    quickSort3Way(arr, m2, r);
  }
  return arr;
}

module.exports = quickSort3Way;
