// Created by WinnoChan at 2024/05/30 23:56
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int maximumLength(string s) {
    int n = s.size();
    vector<vector<int>> cnts(26, vector<int>(n + 1, 0));

    int ans = 0;
    int l = 0;
    int r = 1;
    while (r < n) {
      if (s[r] == s[r - 1]) {
        r++;
        continue;
      }
      int idx = s[l] - 'a';
      int sz = r - l;
      for (int i = ans + 1; i <= sz; i++) {
        cnts[idx][i] += sz - i + 1;
        if (cnts[idx][i] >= 3) {
          ans = max(ans, i);
        }
      }
      l = r++;
    }
    int idx = s[l] - 'a';
    int sz = r - l;
    for (int i = ans + 1; i <= sz; i++) {
      cnts[idx][i] += sz - i + 1;
      if (cnts[idx][i] >= 3) {
        ans = max(ans, i);
      }
    }

    return ans >= 1 ? ans : -1;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->maximumLength(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
