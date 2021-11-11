// by Alexander Nikolskiy

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");

rl.once("line", (line) => {
  const d = parseInt(line, 10);
  rl.once("line", (line) => {
    const m = parseInt(line, 10);
    rl.once("line", (line) => {
      const n = parseInt(line, 10);
      rl.once("line", (line) => {
        const stops = line
              .toString()
              .split(" ").map(v => +v);
        console.log(car(d, m, n, stops));
        process.exit();
      });
    });
  });
});

function car(d, m, n, stops) {
  let refill = 0;
  let last = 0;
  let temp = m;
  let li = 0;
  let i = 0;
  while (i < n) {
    if (last + temp >= d) {
      return refill;
    }
    while ((stops[i] - last) <= temp) {
      temp -= (stops[i] - last);
      last = stops[i];
      i += 1;
    }
    if (i == li) {
      break;
    }
    li = i;
    temp = m;
    refill += 1;
  }
  return -1;
}

module.exports = car;
