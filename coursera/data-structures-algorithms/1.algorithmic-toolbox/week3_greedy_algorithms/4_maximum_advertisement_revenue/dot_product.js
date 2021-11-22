// by Alexander Nikolskiy

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");

rl.once("line", (line) => {
  const n = parseInt(line, 10);

  rl.once("line", (line) => {
    const a = line
      .toString()
      .split(" ")
      .map((s) => +s);

    rl.once("line", (line) => {
      const b = line
        .toString()
        .split(" ")
        .map((s) => +s);
      console.log(dotProduct(n, a, b));
      process.exit();
    });
  });
});

function dotProduct(n, a, b) {
  const an = [];
  const ap = [];
  const bn = [];
  const bp = [];
  a.forEach((v) => {
    if (v < 0) an.push(v);
    else ap.push(v);
  });
  b.forEach((v) => {
    if (v < 0) bn.push(v);
    else bp.push(v);
  });
  an.reverse();
  bn.reverse();

  let ret = 0;
  while (an.length && bn.length) ret += an.pop() * bn.pop();
  while (ap.length && bp.length) ret += ap.pop() * bp.pop();

  an.reverse();
  bn.reverse();
  while (an.length && bp.length) ret += an.pop() * bp.pop();
  while (ap.length && bn.length) ret += ap.pop() * bn.pop();

  return ret;
}

module.exports = dotProduct;
