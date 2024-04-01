function flatten(arr) {
  if (arr.length === 0) return arr;

  if (!Array.isArray(arr[0])) {
    return [arr[0]].concat(flatten(arr.slice(1)));
  } else {
    return flatten(arr[0]).concat(flatten(arr.slice(1)));
  }
}

function isOdd(num) {
  return num % 2 === 1;
}

console.log(
  flatten([1, [2], [[3]], [[[[4, 5]]]]]),
  flatten([]),
  flatten([1, 3, [5, 7], [9, [11]]]),
);
