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
              .split(" ");
        console.log(largestNumber(n, a));
        process.exit();
      });
});

function largestNumber(n, arr) {
  arr = arr.sort((a,b) => {
    let i = 0;
    for ( ; i < a.length && i < b.length ;i++) {
      if (a[i] > b[i]) {
        return -1;
      }
      if (a[i] < b[i]) {
        return 1;
      }
    }
    if (a[i] === undefined) {
      for (let j = i; j < b.length; j++) {
        if (b[j] === b[j - i]) continue;
        if (b[j] > b[j - i]) return 1;
        return -1;
      }
    }
    if (b[i] === undefined) {
      for (let j = i; j < a.length; j++) {
        if (a[j] === a[j - i]) continue;
        if (a[j] > a[j - i]) return -1;
        return 1;
      }
    }
    return 0;
  });
  return arr.join('');
}

module.exports = largestNumber;
