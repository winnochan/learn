// by Alexander Nikolskiy

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");
rl.once("line", (line) => {
  const arr = line.toString().split(" ").slice(1).map(Number);

  rl.once("line", (line) => {
    const keys = line.toString().split(" ").slice(1).map(Number);
    const result = [];

    for (let key of keys) {
      result.push(binarySearch(arr, key));
    }

    const res = result.join(" ");
    const maxLength = 50000;

    for (let i = 0; i < res.length; i += maxLength) {
      process.stdout.write(res.slice(i, i + maxLength));
    }

    process.stdout.write("\n");
    process.exit();
  });
});

/**
 * @param arr number[]
 * @param key number
 */
function binarySearch(arr = [], key) {
  // console.log(arr, key);
  let i = -1;
  let l = 0;
  let r = arr.length - 1;
  while (l <= r) {
    const m = Math.floor((l + r) / 2);
    if (arr[m] == key) {
      i = m;
      break;
    }
    if (arr[m] < key) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  // console.log(key, i, l, r);
  if (i < 0) return i;
  l = 0;
  r = arr.length - 1;
  key -= 0.5;
  while (l <= r) {
    const m = Math.floor((l + r) / 2);
    if (arr[m] == key) return m;
    if (arr[m] < key) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  // console.log(key, i, l, r);
  return l;
}

module.exports = binarySearch;
