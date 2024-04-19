// Created by WinnoChan at 2024/04/20 00:53
// leetgo: 1.4.5
// https://leetcode.cn/problems/combination-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end(), greater<int>());
    vector<vector<int>> ans{};
    vector<int> path{};
    dfs(ans, path, candidates, target, 0);
    return ans;
  }

  void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& candidates, int target, int step) {
    if (target == 0) {
      ans.push_back(path);
      return;
    }
    if (target < 0) {
      return;
    }
    for (auto i = step; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      dfs(ans, path, candidates, target - candidates[i], i);
      path.pop_back();
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> candidates;
  LeetCodeIO::scan(cin, candidates);
  int target;
  LeetCodeIO::scan(cin, target);

  Solution *obj = new Solution();
  auto res = obj->combinationSum(candidates, target);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
