// Created by WinnoChan at 2024/06/06 00:37
// leetgo: 1.4.7
// https://leetcode.cn/problems/separate-black-and-white-balls/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  long long minimumSteps(string s) {
    int n = s.size();
    int r = n - 1;
    while (r >= 0 && s[r] - '0') {
      r--;
    }
    int l = r - 1;
    long long ans = 0;
    while (l >= 0) {
      while (l >= 0 && !(s[l] - '0')) {
        l--;
      }
      if (l >= 0) {
        ans += r - l;
        swap(s[l--], s[r--]);
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

  Solution *obj = new Solution();
  auto res = obj->minimumSteps(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
