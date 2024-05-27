// Created by WinnoChan at 2024/05/28 00:40
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-the-peaks/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> findPeaks(vector<int> &mountain) {
    vector<int> ans{};
    int n = mountain.size();
    for (int i = 1; i < n - 1; i++) {
      if (max(mountain[i - 1], mountain[i + 1]) < mountain[i]) {
        ans.emplace_back(i++);
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> mountain;
  LeetCodeIO::scan(cin, mountain);

  Solution *obj = new Solution();
  auto res = obj->findPeaks(mountain);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
