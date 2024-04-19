// Created by WinnoChan at 2024/04/20 06:50
// leetgo: 1.4.5
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    // [0,left) 表示已经处理好的区域
    // [right,end) 表示还未处理的区域
    int left = 2;
    int right = 2;
    int n = nums.size();
    while (right < n) {
      if (nums[right] == nums[left - 2] && nums[right] == nums[left - 1]) {
        right++;
        continue;
      } else if (left < right) {
        nums[left++] = nums[right++];
      } else {
        left++;
        right++;
      }
    }
    while (left < nums.size()) {
      nums.pop_back();
    }
    // for (const auto& v: nums) {
    //     cout << v << ' ';
    // }
    return nums.size();
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->removeDuplicates(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
