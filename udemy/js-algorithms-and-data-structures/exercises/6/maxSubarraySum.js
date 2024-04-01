function maxSubarraySum(arr, sum){
  if (arr.length < sum) return null;

  let tmp = 0;
  for (let i = 0; i < sum; i++) {
    tmp += arr[i];
  }
  let max = tmp;
  let i = 1;
  while (i + sum <= arr.length) {
    //       console.log(tmp, max);
    tmp = tmp - arr[i - 1] + arr[i + sum - 1];
    if (tmp > max) max = tmp;

    i++;
  }
  return max;
}

console.log(
  maxSubarraySum([2, 3], 3),
  maxSubarraySum([-3, 4, 0, -2, 6, -1], 2),
);
