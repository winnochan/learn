// Created by WinnoChan at 2024/06/08 00:26
// leetgo: 1.4.7
// https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n / 2;
        }
        unordered_map<int, int> memo{};
        memo.reserve(1000);
        return 1 + max({
                       helper(nums, nums[0] + nums[1], 2, n - 1, memo),
                       helper(nums, nums[n - 1] + nums[n - 2], 0, n - 3, memo),
                       helper(nums, nums[0] + nums[n - 1], 1, n - 2, memo),
                   });
    }

    int helper(vector<int>& nums, int val, int l, int r,
               unordered_map<int, int>& memo) {
        if (l >= r) {
            return 0;
        }
        int key = 10000 * l + r;
        if (memo.count(key)) {
            return memo[key];
        }
        memo[key] = max({
            nums[l] + nums[l + 1] == val ? 1 + helper(nums, val, l + 2, r, memo)
                                         : 0,
            nums[r] + nums[r - 1] == val ? 1 + helper(nums, val, l, r - 2, memo)
                                         : 0,
            nums[l] + nums[r] == val ? 1 + helper(nums, val, l + 1, r - 1, memo)
                                     : 0,
        });
        return memo[key];
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->maxOperations(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
