function reverse(str) {
  if (str.length === 1) return str;

  return reverse(str.slice(1)).concat(str[0]);
}

console.log(
  reverse("123456"),
  reverse("131415"),
  reverse("987654"),
  reverse("1541514"),
);
