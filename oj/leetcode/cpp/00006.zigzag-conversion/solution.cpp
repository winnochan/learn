// Created by WinnoChan at 2024/04/21 08:37
// leetgo: 1.4.5
// https://leetcode.cn/problems/zigzag-conversion/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;

    string ans(s);
    int cnt = 0;
    int cyc = (numRows - 1) << 1;
    int sz = s.size();
    int ot = 0;
    for (int r = 0; r < numRows; r++) {
      for (int i = r; i < sz; i += cyc) {
        if (r == 0 || r == numRows - 1) {
          ans[cnt++] = s[i];
        } else {
          ans[cnt++] = s[i];
          ot = i + cyc - (r << 1);
          if (ot < sz) {
            ans[cnt++] = s[ot];
          }
        }
      }
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);
  int numRows;
  LeetCodeIO::scan(cin, numRows);

  Solution *obj = new Solution();
  auto res = obj->convert(s, numRows);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
