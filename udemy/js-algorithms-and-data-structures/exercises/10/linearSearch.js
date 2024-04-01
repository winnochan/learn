function linearSearch(arr, num) {
  if (!Array.isArray(arr)) return -1;

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === num) return i;
  }
  return -1;
}

console.log(
  linearSearch([], 7),
  linearSearch([1, 3, 5, 7, 9, 11], 7),
  linearSearch([1, 3, 11], 7),
  linearSearch([9, 8, 7, 6, 5, 4, 3, 2, 1], 10),
  linearSearch([100], 200),
  linearSearch([100], 100),
);
