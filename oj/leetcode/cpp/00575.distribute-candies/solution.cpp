// Created by WinnoChan at 2024/06/02 21:04
// leetgo: 1.4.7
// https://leetcode.cn/problems/distribute-candies/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int distributeCandies(vector<int> &candyType) {
    unordered_set<int> types{};

    for (const auto &t : candyType) {
      types.insert(t);
    }

    return min(candyType.size() / 2, types.size());
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> candyType;
  LeetCodeIO::scan(cin, candyType);

  Solution *obj = new Solution();
  auto res = obj->distributeCandies(candyType);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
