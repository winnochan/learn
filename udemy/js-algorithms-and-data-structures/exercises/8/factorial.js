function factorial(num) {
  if (num <= 1) return 1;

  return num * factorial(num - 1);
}

console.log(
  factorial(2),
  factorial(3),
  factorial(4),
  factorial(5),
);
