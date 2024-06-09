// Created by WinnoChan at 2024/06/09 21:38
// leetgo: 1.4.7
// https://leetcode.cn/problems/burst-balloons/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  vector<vector<int>> memo{};
  vector<int> data{};

public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();

    data.resize(n + 2, 1);
    memo.resize(n + 2, vector<int>(n + 2, -1));
    for (int i = 1; i <= n; i++) {
      data[i] = nums[i - 1];
    }

    return helper(0, n + 1);
  }

  int helper(int i, int j) {
    if (i >= j - 1) {
      return 0;
    }
    int &val = memo[i][j];
    if (val >= 0) {
      return val;
    }
    for (int m = i + 1; m < j; m++) {
      int cal = data[i] * data[m] * data[j] + helper(i, m) + helper(m, j);
      if (cal > val) {
        val = cal;
      }
    }
    return val;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->maxCoins(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
