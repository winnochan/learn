// Created by WinnoChan at 2024/06/07 00:22
// leetgo: 1.4.7
// https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxOperations(vector<int> &nums) {
    int val = nums.size() > 1 ? nums[0] + nums[1] : 0;

    reverse(nums.begin(), nums.end());

    nums.pop_back();
    nums.pop_back();

    int ans = val > 0 ? 1 : 0;
    while (nums.size() > 1) {
      if (nums[nums.size() - 1] + nums[nums.size() - 2] == val) {
        ans++;
        nums.pop_back();
        nums.pop_back();
      } else {
        break;
      }
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
  auto res = obj->maxOperations(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
