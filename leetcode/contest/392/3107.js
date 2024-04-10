/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperationsToMakeMedianK = function (nums, k) {
  nums = nums.sort((a, b) => a - b);
  let size = nums.length;
  // console.log(nums, k);
  if (size % 2) {
    return helper(nums, 0, size - 1, k);
  } else {
    return helper(nums, 0, size - 1, k);
    // return Math.min(helper(nums, 0, size - 2, k), helper(nums, 1, size - 1, k));
  }
};

function helper(nums, l, r, k) {
  let mid = l + ((r - l) >> 1);
  if (nums.length % 2 === 0) {
    mid += 1;
  }

  if (nums[mid] === k) return 0;

  let ans = 0;
  // console.log(nums, l, r, k, mid);
  if (nums[mid] > k) {
    ans += nums[mid] - k;
    let i = mid - 1;
    while (i >= l && nums[i] > k) {
      ans += nums[i--] - k;
    }
  } else {
    ans += k - nums[mid];
    let i = mid + 1;
    while (i <= r && nums[i] < k) {
      ans += k - nums[i++];
    }
  }

  return ans;
}

// console.log(minOperationsToMakeMedianK([2, 5, 6, 8, 5], 4));
// console.log(minOperationsToMakeMedianK([2, 5, 6, 8, 5], 7));
// console.log(minOperationsToMakeMedianK([1, 2, 3, 4, 5, 6], 4));
// console.log(minOperationsToMakeMedianK([45, 50, 89, 30, 4, 5, 91, 58], 31));
// console.log(minOperationsToMakeMedianK([29, 45, 53, 98, 37, 53], 2));
console.log(minOperationsToMakeMedianK([47, 60], 47));
console.log(minOperationsToMakeMedianK([47, 60], 70));
