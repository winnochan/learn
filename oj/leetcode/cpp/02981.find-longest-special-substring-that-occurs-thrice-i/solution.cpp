// Created by WinnoChan at 2024/05/29 01:22
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int maximumLength(string s) {
    int n = s.size();
    unordered_map<string, int> cnt{};
    for (int k = n - 2; k >= 1; k--) {
      for (int i = 0; i <= n - k; i++) {
        bool flag = true;
        for (int j = i + 1; j < i + k; j++) {
          if (s[j] != s[j - 1]) {
            flag = false;
            break;
          }
        }
        if (!flag) {
          continue;
        }
        auto ss = s.substr(i, k);
        cnt[ss]++;
        // cout << ss << " | " << cnt[ss] << endl;
        if (cnt[ss] >= 3) {
          return k;
        }
      }
    }
    return -1;
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
