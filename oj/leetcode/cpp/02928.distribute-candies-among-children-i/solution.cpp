// Created by WinnoChan at 2024/06/01 01:02
// leetgo: 1.4.7
// https://leetcode.cn/problems/distribute-candies-among-children-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int distributeCandies(int n, int limit) {
    vector<vector<int>> memo(4, vector<int>(n + 1, -1));
    return helper(n, limit, 3, memo);
  }

  int helper(int n, int limit, int step, vector<vector<int>> &memo) {
    if (n < 0 || n > limit * step) {
      memo[step][n] = 0;
      return 0;
    }
    int &ans = memo[step][n];
    if (ans >= 0) {
      return ans;
    }
    if (step == 0) {
      ans = 1;
      return ans;
    }
    ans = 0;
    for (int i = max(0, n - limit * (step - 1)); i <= min(n, limit); i++) {
      ans += helper(n - i, limit, step - 1, memo);
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);
  int limit;
  LeetCodeIO::scan(cin, limit);

  Solution *obj = new Solution();
  auto res = obj->distributeCandies(n, limit);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
