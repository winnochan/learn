// Created by WinnoChan at 2024/05/22 01:09
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-players-with-zero-or-one-losses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    int n = matches.size();
    int maxId = 0;
    for (const auto &res : matches) {
      maxId = max({maxId, res[0], res[1]});
    }
    vector<bool> users(maxId + 1, false);
    vector<int> degrees(maxId + 1, 0);

    for (const auto &res : matches) {
      users[res[0]] = true;
      users[res[1]] = true;
      degrees[res[1]]++;
    }

    vector<int> ans1{};
    vector<int> ans2{};
    for (int i = 1; i <= maxId; i++) {
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
