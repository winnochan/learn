// Created by WinnoChan at 2024/06/15 00:38
// leetgo: 1.4.7
// https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int maximumBeauty(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 1;
    int l = 0;
    int r = 1;
    int d = 2 * k;
    while (r < n) {
      while (r < n && nums[r] - nums[l] <= d) {
        r++;
      }
      ans = max(ans, ++r - ++l);
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
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->maximumBeauty(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
