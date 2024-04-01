function recursiveRange(num) {
  if (num < 1) return 0;

  if (num === 1) return 1;

  return num + recursiveRange(num - 1);
}

console.log(
  recursiveRange(2),
  recursiveRange(3),
  recursiveRange(4),
  recursiveRange(5),
);
