// Created by WinnoChan at 2024/04/27 03:31
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> findColumnWidth(vector<vector<int>> &grid) {
    int m = grid.size();
    if (!m)
      return {};

    int n = grid[0].size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[i] = max(ans[i], getLen(grid[j][i]));
      }
    }

    return ans;
  }

  int getLen(int n) {
    if (n < 0)
      return 1 + getLen(-n);
    int ans = 0;
    while (n > 0) {
      ans++;
      n /= 10;
    }
    return max(ans, 1);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> grid;
  LeetCodeIO::scan(cin, grid);

  Solution *obj = new Solution();
  auto res = obj->findColumnWidth(grid);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
