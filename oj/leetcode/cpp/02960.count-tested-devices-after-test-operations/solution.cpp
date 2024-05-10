// Created by WinnoChan at 2024/05/11 00:19
// leetgo: 1.4.5
// https://leetcode.cn/problems/count-tested-devices-after-test-operations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int countTestedDevices(vector<int> &batteryPercentages) {
    int ans = 0;
    int n = batteryPercentages.size();
    // 改成差分数组
    for (int i = n - 1; i > 0; i--) {
      batteryPercentages[i] -= batteryPercentages[i - 1];
    }
    int psum = 0;
    for (int i = 0; i < n - 1; i++) {
      // 差分数组的前i个前缀和等于原数组的第i个值
      psum += batteryPercentages[i];
      if (psum <= 0) {
        continue;
      }
      ans++;
      // 把差分数组的第i + 1个值减1相当于把后面所有的原数组数值减1
      batteryPercentages[i + 1] -= 1;
    }
    if (psum + batteryPercentages[n - 1] > 0) {
      ans++;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> batteryPercentages;
  LeetCodeIO::scan(cin, batteryPercentages);

  Solution *obj = new Solution();
  auto res = obj->countTestedDevices(batteryPercentages);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
