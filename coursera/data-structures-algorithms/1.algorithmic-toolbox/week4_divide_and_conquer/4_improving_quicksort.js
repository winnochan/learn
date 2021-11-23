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

    console.log(quickSort(arr));
    process.exit();
  });
});

function quickSort(arr = []) {
  arr.sort((a, b) => a - b);
  return arr;
}

module.exports = quickSort;
