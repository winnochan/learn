function someRecursive(arr, cb) {
  if (arr.length === 0) return false;

  if (cb(arr.pop())) return true;

  return someRecursive(arr, cb);
}

function isOdd(num) {
  return num % 2 === 1;
}

console.log(
  someRecursive([1, 2, 3, 4], isOdd),
  someRecursive([2, 4, 6, 8], isOdd),
  someRecursive([1, 0, 2, 4], isOdd),
  someRecursive([2, 0, 4, 8], isOdd),
);
