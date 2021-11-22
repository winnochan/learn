// by Alexander Nikolskiy

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");
rl.on("line", readLine);

function readLine(line) {
  console.log(fib(parseInt(line, 10)));
  process.exit();
}

function fib(n) {
  const arr = [0, 1];
  for (let i = 2; i <= n; i++) {
    arr.push((arr[i - 2] + arr[i - 1]) % 10);
    if (arr[i - 1] === arr[0] && arr[i] === arr[1]) {
      arr.pop();
      arr.pop();
      break;
    }
  }
  return arr[n % arr.length];
}

module.exports = fib;
