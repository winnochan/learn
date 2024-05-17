// Created by WinnoChan at 2024/05/18 01:02
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-the-maximum-divisibility-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int maxDivScore(vector<int> &nums, vector<int> &divisors) {
    int ans = divisors[0], maxv = 0, temp;
    for (const auto &div : divisors) {
      temp = 0;
      for (const auto &val : nums) {
        if (val % div == 0) {
          temp++;
        }
      }
      if (temp > maxv) {
        ans = div;
        maxv = temp;
      } else if (temp == maxv) {
        ans = min(ans, div);
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  vector<int> divisors;
  LeetCodeIO::scan(cin, divisors);

  Solution *obj = new Solution();
  auto res = obj->maxDivScore(nums, divisors);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
