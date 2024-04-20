// Created by WinnoChan at 2024/04/20 08:48
// leetgo: 1.4.5
// https://leetcode.cn/problems/factorial-trailing-zeroes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int trailingZeroes(int n) {
    int ans = 0;
    while (n > 0) {
      n /= 5;
      ans += n;
    }
    return ans;
  }

  int dp(int n) {
    int dpc[10001]{0};
    int dpn[10001]{1};

    for (auto i = 1; i <= n; i++) {
      int v = i * dpn[i - 1];
      int cnt = 0;
      while (v % 10 == 0) {
        v /= 10;
        cnt++;
      }
      dpc[i] = dpc[i - 1] + cnt;
      dpn[i] = v % 100000;
    }

    return dpc[n];
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->trailingZeroes(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
