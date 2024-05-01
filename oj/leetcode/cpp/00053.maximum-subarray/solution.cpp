// Created by WinnoChan at 2024/05/02 03:30
// leetgo: 1.4.5
// https://leetcode.cn/problems/maximum-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] >= 0) {
        nums[i] += nums[i - 1];
      }
      ans = max(ans, nums[i]);
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->maxSubArray(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
