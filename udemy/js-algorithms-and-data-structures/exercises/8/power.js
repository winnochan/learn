function power(base, exp) {
  if (exp === 0) return 1;

  return base * power(base, exp - 1);
}

console.log(
  power(2, 0),
  power(2, 1),
  power(2, 2),
  power(2, 3),
);
