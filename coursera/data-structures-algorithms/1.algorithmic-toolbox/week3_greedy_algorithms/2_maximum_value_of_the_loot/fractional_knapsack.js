// by Alexander Nikolskiy

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    terminal: false
});

process.stdin.setEncoding('utf8');

rl.once('line', line => {
    const [itemsCount, knapsackCapacity] = line.toString().split(' ').map(Number);
    const values = [];
    const weights = [];
    let count = 0;

    rl.on('line', line => {
        const [v, w] = readLine(line);
        values.push(v);
        weights.push(w);

        if (++count >= itemsCount) {
            console.log(max(itemsCount, knapsackCapacity, values, weights));
            process.exit();
        }
    });
});

function readLine(line) {
    const v = parseInt(line.toString().split(' ')[0], 10);
    const w = parseInt(line.toString().split(' ')[1], 10);

    return [v, w];
}

function max(count, capacity, values, weights) {
  let val = 0;
  units = values.map((v, i) => [v / weights[i], i]).sort();
  while (units.length) {
    if (capacity <= 0) break;
    const [unit, index] = units.pop();
    if (weights[index] <= capacity) {
      capacity -= weights[index];
      val += values[index];
    } else {
      val += values[index] * capacity / weights[index];
      capacity = 0;
    }
  }
  return val.toFixed(4);
}

module.exports = max;
