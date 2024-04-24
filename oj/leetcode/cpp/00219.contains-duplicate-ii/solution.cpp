// Created by WinnoChan at 2024/04/24 22:40
// leetgo: 1.4.5
// https://leetcode.cn/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    for (int i = 0; i <= min(k, n - 1); i++) {
      cnt[nums[i]]++;
      if (cnt[nums[i]] >= 2) {
        return true;
      }
    }
    for (int i = k + 1; i < n; i++) {
      cnt[nums[i - k - 1]]--;
      cnt[nums[i]]++;
      if (cnt[nums[i]] >= 2) {
        return true;
      }
    }
    return false;
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
  auto res = obj->containsNearbyDuplicate(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
