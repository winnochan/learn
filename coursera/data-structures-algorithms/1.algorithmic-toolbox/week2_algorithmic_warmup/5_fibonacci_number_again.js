// by Alexander Nikolskiy

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");
rl.on("line", readLine);

function readLine(line) {
  if (line !== "\n") {
    const n = parseInt(line.toString().split(" ")[0], 10);
    const m = parseInt(line.toString().split(" ")[1], 10);

    console.log(getFibMod(n, m));
    process.exit();
  }
}

function getFibMod(n, m) {
  const arr = [0, 1];
  for (let i = 2; i <= n; i++) {
    arr.push((arr[i - 2] + arr[i - 1]) % m);
    if (arr[i - 1] === arr[0] && arr[i] === arr[1]) {
      arr.pop();
      arr.pop();
      break;
    }
  }
  return arr[n % arr.length];
}

module.exports = getFibMod;
