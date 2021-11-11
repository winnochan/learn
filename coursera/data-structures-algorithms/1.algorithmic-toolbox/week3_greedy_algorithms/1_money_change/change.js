// by Alexander Nikolskiy

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  terminal: false,
});

process.stdin.setEncoding("utf8");
rl.on("line", readLine);

function readLine(line) {
  console.log(change(parseInt(line, 10)));
  process.exit();
}

function change(n) {
  let i = Math.floor(n / 10);
  n %= 10;
  i += Math.floor(n / 5 );
  n %= 5;
  i += n;
  return i;
}

module.exports = change;
