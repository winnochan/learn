// Created by WinnoChan at 2024/05/31 00:06
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-missing-and-repeated-values/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> cnt(n * n + 1, 0);
    int a, b;
    for (const auto &vec : grid) {
      for (const auto val : vec) {
        cnt[val]++;
        if (cnt[val] > 1) {
          a = val;
        }
      }
    }
    for (int i = 1; i <= n * n; i++) {
      if (!cnt[i]) {
        b = i;
      }
    }
    return {a, b};
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> grid;
  LeetCodeIO::scan(cin, grid);

  Solution *obj = new Solution();
  auto res = obj->findMissingAndRepeatedValues(grid);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
