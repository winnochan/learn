// fibonacci
function fib(num) {
  if (num <= 2) return 1;

  return fib(num - 1) + fib(num - 2);
}

console.log(
  fib(1),
  fib(2),
  fib(3),
  fib(28),
);
