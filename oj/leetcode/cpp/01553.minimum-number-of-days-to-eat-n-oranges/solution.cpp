// Created by WinnoChan at 2024/05/12 03:08
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-number-of-days-to-eat-n-oranges/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int minDays(int n) {
    if (n <= 1) {
      return n;
    }
    int &ans = memo[n];
    if (ans > 0) {
      return ans;
    }
    ans = 1 + min((n % 2) + minDays(n / 2), (n % 3) + minDays(n / 3));
    return ans;
  }

private:
  unordered_map<int, int> memo;
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->minDays(n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
