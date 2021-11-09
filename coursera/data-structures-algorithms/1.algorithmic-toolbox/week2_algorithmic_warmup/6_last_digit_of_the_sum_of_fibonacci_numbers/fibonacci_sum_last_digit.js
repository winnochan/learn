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

const arr = [
  0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5,
  3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4,
  9, 3, 2, 5, 7, 2, 9, 1,
];
const a = arr.reduce((prev, curr) => prev + curr, 0);

function fib(n) {
  const b = arr
    .slice(0, (n % arr.length) + 1)
    .reduce((prev, curr) => prev + curr, 0);
  // console.log(arr, a, b);
  const final = a * Math.floor(n / arr.length) + b;
  return final % 10;
}

module.exports = fib;
