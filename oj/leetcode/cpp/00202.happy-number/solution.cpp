// Created by WinnoChan at 2024/04/24 22:34
// leetgo: 1.4.5
// https://leetcode.cn/problems/happy-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isHappy(int n) {
    int ans, mod;
    unordered_set<int> cnt;
    while (n) {
      ans = 0;
      while (n) {
        mod = n % 10;
        n /= 10;
        ans += mod * mod;
      }
      n = ans;
      if (n == 1) {
        return true;
      }
      if (cnt.count(n)) {
        return false;
      }
      cnt.insert(n);
    }
    return false;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->isHappy(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
