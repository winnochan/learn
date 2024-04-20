// Created by WinnoChan at 2024/04/21 00:26
// leetgo: 1.4.5
// https://leetcode.cn/problems/combination-sum-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(ans, path, k, 1, n);
    return ans;
  }

  void dfs(vector<vector<int>>& ans, vector<int>& path, int k, int low, int n) {
    if (k <= 0) {
      if (n <= 0) {
        ans.push_back(path);
      }
      return;
    }
    for (int j = low; j <= min(9, n / k); ++j) {
      path.push_back(j);
      dfs(ans, path, k - 1, j + 1, n - j);
      path.pop_back();
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int k;
  LeetCodeIO::scan(cin, k);
  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->combinationSum3(k, n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
