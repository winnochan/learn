// Created by WinnoChan at 2024/04/25 01:05
// leetgo: 1.4.5
// https://leetcode.cn/problems/total-distance-traveled/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int ans = 10 * mainTank;
    while (mainTank >= 5 && additionalTank > 0) {
      mainTank -= 4;
      ans += 10;
      additionalTank -= 1;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int mainTank;
  LeetCodeIO::scan(cin, mainTank);
  int additionalTank;
  LeetCodeIO::scan(cin, additionalTank);

  Solution *obj = new Solution();
  auto res = obj->distanceTraveled(mainTank, additionalTank);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
