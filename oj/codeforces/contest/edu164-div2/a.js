const rl = require("readline").createInterface({ input: process.stdin });
const it = rl[Symbol.asyncIterator]();
const readline = async () => (await it.next()).value;

async function main() {
  let T = +(await readline());

  while (T--) {
    let [N, M, K] = (await readline()).split(" ").map(Number);

    console.log(N, M, K);
  }

  process.exit(0);
}

main();
