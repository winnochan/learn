const rl = require("readline").createInterface({ input: process.stdin });
const it = rl[Symbol.asyncIterator]();
const readline = async () => (await it.next()).value;

function multi(x, y) {
  let xa = x.split("").map(Number).reverse();
  let ya = y.split("").map(Number).reverse();
  let ra = new Array(xa.length + ya.length + 1).fill(0);

  for (let i = 0; i < xa.length; i++) {
    let ca = 0;
    for (let j = 0; j < ya.length; j++) {
      let val = xa[i] * ya[j] + ca;
      ra[i + j] += val % 10;
      ca = Math.floor(val / 10);
    }
    if (ca) {
      ra[i + ya.length] += ca;
    }
  }
  console.log(ra);
}

async function main() {
  let T = +(await readline());

  while (T--) {
    let x = await readline();
    let y = await readline();

    console.log(multi(x, y));
  }

  process.exit(0);
}

main();
