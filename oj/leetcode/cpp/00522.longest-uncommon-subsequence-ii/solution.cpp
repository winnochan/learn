// Created by WinnoChan at 2024/06/18 00:50
// leetgo: 1.4.7
// https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int findLUSlength(vector<string> &strs) {
    sort(strs.begin(), strs.end(),
         [&](string &a, string &b) -> bool { return a.size() > b.size(); });

    int n = strs.size();
    for (int i = 0; i < n; i++) {
      bool flag = true;
      for (int j = 0; flag && j < n; j++) {
        if (j == i)
          continue;
        if (check(strs[i], strs[i].size() - 1, strs[j], strs[j].size() - 1)) {
          flag = false;
        }
      }
      if (flag) {
        return strs[i].size();
      }
    }
    return -1;
  }

  bool check(const string &a, int an, const string &b, int bn) {
    if (an > bn)
      return false;
    if (an < 0)
      return true;
    return a[an] == b[bn] ? check(a, an - 1, b, bn - 1)
                          : check(a, an, b, bn - 1);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> strs;
  LeetCodeIO::scan(cin, strs);

  Solution *obj = new Solution();
  auto res = obj->findLUSlength(strs);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
