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
          .split(" ")
          .map((v) => +v);
        console.log(car(d, m, n, stops));
        process.exit();
      });
    });
  });
});

function car(d, m, n, stops) {
  stops = [0, ...stops, d];
  // console.log(d, m, n, stops);
  let li = 0;
  let i = 1;
  let ret = 0;
  while (i < stops.length) {
    if (stops[i] - stops[li] <= m) {
      i++;
      continue;
    }
    if (li == i - 1) {
      return -1;
    }
    li = i - 1;
    // console.log("refill at", stops[li]);
    ret += 1;
  }
  return stops[stops.length - 1] - stops[li] <= m ? ret : -1;
}

module.exports = car;
