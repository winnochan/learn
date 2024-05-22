// Created by WinnoChan at 2024/05/22 01:09
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-players-with-zero-or-one-losses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
  static constexpr int MAXN = 1e5 + 1;

public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    int users[MAXN]{0};
    int degrees[MAXN]{0};

    for (const auto &res : matches) {
      users[res[0]] = 1;
      users[res[1]] = 1;
      degrees[res[1]]++;
    }

    vector<int> ans1{};
    vector<int> ans2{};
    for (int i = 1; i < MAXN; i++) {
      if (!users[i]) {
        continue;
      }
      if (degrees[i] == 0) {
        ans1.push_back(i);
      } else if (degrees[i] == 1) {
        ans2.push_back(i);
      }
    }

    return {ans1, ans2};
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> matches;
  LeetCodeIO::scan(cin, matches);

  Solution *obj = new Solution();
  auto res = obj->findWinners(matches);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
