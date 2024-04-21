// Created by WinnoChan at 2024/04/22 07:41
// leetgo: 1.4.5
// https://leetcode.cn/problems/combinations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(ans, path, 1, n, k);
    return ans;
  }

  void dfs(vector<vector<int>> &ans, vector<int> &path, int s, int n, int k) {
    if (!k) {
      ans.push_back(path);
      return;
    }
    if (s > n)
      return;

    for (int i = s; i <= n; i++) {
      path.push_back(i);
      dfs(ans, path, i + 1, n, k - 1);
      path.pop_back();
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->combine(n, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
