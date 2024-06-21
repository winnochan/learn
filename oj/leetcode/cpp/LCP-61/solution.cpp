// Created by WinnoChan at 2024/06/21 23:18
// leetgo: 1.4.7
// https://leetcode.cn/problems/6CE719/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int temperatureTrend(vector<int> &temperatureA, vector<int> &temperatureB) {
    int n = temperatureA.size();

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int j = i + 1;
      for (; j < n; j++) {
        if (temperatureA[j] > temperatureA[j - 1] &&
            temperatureB[j] <= temperatureB[j - 1]) {
          break;
        }
        if (temperatureA[j] < temperatureA[j - 1] &&
            temperatureB[j] >= temperatureB[j - 1]) {
          break;
        }
        if (temperatureA[j] == temperatureA[j - 1] &&
            temperatureB[j] != temperatureB[j - 1]) {
          break;
        }
      }
      ans = max(ans, j - i - 1);
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> temperatureA;
  LeetCodeIO::scan(cin, temperatureA);
  vector<int> temperatureB;
  LeetCodeIO::scan(cin, temperatureB);

  Solution *obj = new Solution();
  auto res = obj->temperatureTrend(temperatureA, temperatureB);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
