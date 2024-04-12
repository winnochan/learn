const rl = require("readline").createInterface({ input: process.stdin });
const it = rl[Symbol.asyncIterator]();
const readline = async () => (await it.next()).value;

async function main() {
  let T = +(await readline());

  while (T--) {
    let N = +(await readline());
    let arr = (await readline()).split(" ").map(Number);

    // console.log(N, arr);
  }

  process.exit(0);
}

main();
