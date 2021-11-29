const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

console.log(quickSort3Way([2, 4, 2, 3, 9, 7, 2, 5]));

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

// 2,3,4,2,5,9,7,2
// 2 4 3 2 5 9 7 2
// 2 2 3 2 5 9 7 4
function partition(arr = [], left, right) {
  if (right - left <= 1) return arr;
  if (right - left == 2) {
    if (arr[left] > arr[right]) {
      const temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }
    return arr;
  }
  const val = arr[left + 1];
  let mid = left + 1;
  let temp;
  while (mid < right) {
    while (arr[right] > val) right--;
    if (arr[right] == val && mid + 1 < right) {
      mid += 1;
      temp = arr[mid];
      arr[mid] = arr[right];
      arr[right] = temp;
    }

    while (arr[left] < val) left++;
    if (arr[left] == val && left <= mid) {
      mid += 1;
      temp = arr[mid];
      arr[mid] = arr[left];
      arr[left] = temp;
    }

    if (left < right && arr[left] > arr[right]) {
      temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }

    console.log(JSON.stringify(arr), val, left, right);
    // while (mid < right && arr[right] >= val) {
    //   if (arr[right] == val) {
    //     mid += 1;
    //     arr[right] = arr[mid];
    //     arr[mid] = val;
    //   } else {

    //   }
    // }

    // while (mid < right && arr[left] <= val) {
    //   if (arr[left] == val) {
    //     mid += 1;
    //     arr[left] = arr[mid];
    //     arr[mid] = val;
    //   } else {

    //   }
    // }
  }
  // console.log(left, right);
  return [left - 1, right];
}

function quickSort3Way(arr = [], l = 0, r = null) {
  if (r === null) {
    r = arr.length - 1;
    // shuffle(arr);
    // console.log("shuffle", arr);
  }
  const [m1, m2] = partition(arr, l, r);
  if (l < m1) {
    quickSort3Way(arr, l, m1);
  }
  if (m2 < r) {
    quickSort3Way(arr, m2, r);
  }
  return arr;
}

module.exports = quickSort3Way;
