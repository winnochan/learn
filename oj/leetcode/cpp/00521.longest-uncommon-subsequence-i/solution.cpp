// Created by WinnoChan at 2024/06/16 00:23
// leetgo: 1.4.7
// https://leetcode.cn/problems/longest-uncommon-subsequence-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int findLUSlength(string a, string b) {
    int an = a.size();
    int bn = b.size();
    if (an == bn) {
      return a == b ? -1 : an;
    }
    return max(an, bn);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string a;
  LeetCodeIO::scan(cin, a);
  string b;
  LeetCodeIO::scan(cin, b);

  Solution *obj = new Solution();
  auto res = obj->findLUSlength(a, b);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
