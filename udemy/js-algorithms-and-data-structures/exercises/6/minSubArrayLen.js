function minSubArrayLen(arr, target) {
  if (!Array.isArray(arr) || arr.length < 1) return 0;

  if (arr[0] >= target) return 1;

  let l = 0, r = 1, sum = arr[0] + arr[1], len = arr.length + 1;

  while (r < arr.length) {
    if (sum < target) {
      sum += arr[++r];
    } else {
      len = Math.min(len, r - l + 1);
      sum -= arr[l++];
    }
  }

  return len <= arr.length ? len : 0;
}

console.log(
  minSubArrayLen([2, 1, 6, 5, 4], 9),
  minSubArrayLen([2, 3, 1, 2, 4, 3], 7),
);
