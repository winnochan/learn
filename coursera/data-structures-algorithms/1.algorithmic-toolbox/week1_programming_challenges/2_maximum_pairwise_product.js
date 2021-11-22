// by Alexander Nikolskiy

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");
rl.once("line", () => {
  rl.on("line", readLine);
});

function readLine(line) {
  const arr = line.toString().split(" ").map(Number);

  console.log(max(arr));
  process.exit();
}

function max(arr = []) {
  let first = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > arr[first]) {
      first = i;
    }
  }
  let second = first > 0 ? 0 : 1;
  for (let i = 0; i < arr.length; i++) {
    if (i != first && arr[i] > arr[second]) {
      second = i;
    }
  }
  return arr[first] * arr[second];
}

module.exports = max;
