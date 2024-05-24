// Created by WinnoChan at 2024/05/25 06:35
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> findIndices(vector<int> &nums, int indexDifference,
                          int valueDifference) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + indexDifference; j < n; j++) {
        if (abs(nums[i] - nums[j]) >= valueDifference) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int indexDifference;
  LeetCodeIO::scan(cin, indexDifference);
  int valueDifference;
  LeetCodeIO::scan(cin, valueDifference);

  Solution *obj = new Solution();
  auto res = obj->findIndices(nums, indexDifference, valueDifference);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
