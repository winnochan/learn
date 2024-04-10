/**
 * @param {number[]} nums
 * @return {number}
 */
var longestMonotonicSubarray = function (nums) {
  let size = nums.length;
  let dp1 = new Array(size).fill(1);
  let dp2 = new Array(size).fill(1);

  let max = 1;
  for (let i = 1; i < size; i++) {
    if (nums[i] > nums[i - 1]) {
      dp1[i] += dp1[i - 1];
      if (dp1[i] > max) {
        max = dp1[i];
      }
    } else if (nums[i] < nums[i - 1]) {
      dp2[i] += dp2[i - 1];
      if (dp2[i] > max) {
        max = dp2[i];
      }
    }
  }
  // console.log(dp1, dp2);

  return max;
};

console.log(longestMonotonicSubarray([3, 2, 1]));
