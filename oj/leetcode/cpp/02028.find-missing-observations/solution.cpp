// Created by WinnoChan at 2024/05/27 22:35
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-missing-observations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int m = rolls.size();

    int diff = 0;
    for (const auto val : rolls) {
      diff += val - mean;
    }
    int total = mean * n - diff;
    if (total < n || total > 6 * n) {
      return {};
    }
    vector<int> ans(n, total / n);
    for (int i = 0; i < total % n; i++) {
      ans[i]++;
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> rolls;
  LeetCodeIO::scan(cin, rolls);
  int mean;
  LeetCodeIO::scan(cin, mean);
  int n;
  LeetCodeIO::scan(cin, n);

  Solution *obj = new Solution();
  auto res = obj->missingRolls(rolls, mean, n);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
