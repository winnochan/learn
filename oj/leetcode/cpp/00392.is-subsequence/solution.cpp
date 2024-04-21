// Created by WinnoChan at 2024/04/22 05:50
// leetgo: 1.4.5
// https://leetcode.cn/problems/is-subsequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isSubsequence(string s, string t) {
    return helper(s, s.size() - 1, t, t.size() - 1);
  }

  bool helper(string &s, int si, string &t, int ti) {
    if (si < 0)
      return true;
    if (ti < 0)
      return false;

    if (s[si] == t[ti])
      return helper(s, si - 1, t, ti - 1);
    return helper(s, si, t, ti - 1);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);
  string t;
  LeetCodeIO::scan(cin, t);

  Solution *obj = new Solution();
  auto res = obj->isSubsequence(s, t);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
