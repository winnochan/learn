// Created by WinnoChan at 2024/05/14 02:02
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> cnt{};
    for (const auto val : tasks) {
      cnt[val]++;
    }
    int ans = 0;
    for (const auto &kv : cnt) {
      int val = kv.second;
      if (val == 1) {
        return -1;
      }
      if (val % 3 == 1) {
        ans += (val - 4) / 3 + 2;
      } else if (val % 3 == 2) {
        ans += val / 3 + 1;
      } else {
        ans += val / 3;
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> tasks;
  LeetCodeIO::scan(cin, tasks);

  Solution *obj = new Solution();
  auto res = obj->minimumRounds(tasks);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
