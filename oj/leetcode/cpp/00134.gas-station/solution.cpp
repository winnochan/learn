// Created by WinnoChan at 2024/04/21 13:09
// leetgo: 1.4.5
// https://leetcode.cn/problems/gas-station/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sum = 0;
    int n = gas.size();
    int i = 0, j = 1, k = 0;
    while (i < n) {
      // printf("i=%d,sum=%d\n", i, sum);
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        i++;
        continue;
      }

      j = 1;
      for (; j < n; j++) {
        k = (i + j) % n;
        sum += gas[k] - cost[k];
        // printf("i=%d,k=%d,sum=%d\n", i, k, sum);
        if (sum < 0) {
          break;
        }
      }
      // printf("i=%d,k=%d,sum=%d\n", i, k, sum);
      if (sum >= 0 && i == (k + 1) % n) {
        return i;
      } else {
        i += j;
        sum = 0;
      }
    }

    return -1;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> gas;
  LeetCodeIO::scan(cin, gas);
  vector<int> cost;
  LeetCodeIO::scan(cin, cost);

  Solution *obj = new Solution();
  auto res = obj->canCompleteCircuit(gas, cost);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
