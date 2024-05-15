// Created by WinnoChan at 2024/05/16 01:07
// leetgo: 1.4.5
// https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  long long numberOfWeeks(vector<int> &milestones) {
    int n = milestones.size();
    if (n <= 1) {
      return n;
    }
    int maxVal = milestones[0];
    long long oneSum = maxVal;
    for (int i = 1; i < n; i++) {
      oneSum += milestones[i];
      maxVal = max(maxVal, milestones[i]);
    }
    long long twoSum = oneSum - maxVal;
    if (maxVal <= twoSum + 1) {
      return oneSum;
    }
    return 2 * twoSum + 1;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> milestones;
  LeetCodeIO::scan(cin, milestones);

  Solution *obj = new Solution();
  auto res = obj->numberOfWeeks(milestones);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
