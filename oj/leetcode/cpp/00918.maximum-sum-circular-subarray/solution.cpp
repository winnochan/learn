// Created by WinnoChan at 2024/06/08 20:21
// leetgo: 1.4.7
// https://leetcode.cn/problems/maximum-sum-circular-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int maxPrefix = nums[0];
    int maxRange = nums[0];
    int minPrefix = nums[0];
    int minRange = nums[0];

    int n = nums.size();
    for (int i = 1; i < n; i++) {
      // 前缀和
      nums[i] += nums[i - 1];
      // nums[i] - minPrefix 为以 i 结尾的最大子数组和
      maxRange = max(maxRange, minPrefix < 0 ? nums[i] - minPrefix : nums[i]);
      // nums[i] - maxPrefix 为以 i 结尾的最小子数组和
      minRange = min(minRange, maxPrefix > 0 ? nums[i] - maxPrefix : nums[i]);

      // 更新历史最大值, 最小值
      maxPrefix = max(maxPrefix, nums[i]);
      minPrefix = min(minPrefix, nums[i]);
    }

    if (maxPrefix < 0) {
      return maxRange;
    }
    return max(maxRange, nums[n - 1] - minRange);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->maxSubarraySumCircular(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
