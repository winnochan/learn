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

    console.log(majorityElement(arr));
    process.exit();
  });
});

function majorityElement(arr = []) {
  const map = {};
  for (const num of arr) {
    if (!map[num]) {
      map[num] = 1;
    } else {
      map[num] += 1;
    }
    if (map[num] > arr.length / 2) {
      return 1;
    }
  }
  return 0;
}

module.exports = majorityElement;
