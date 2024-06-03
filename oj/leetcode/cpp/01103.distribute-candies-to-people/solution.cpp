// Created by WinnoChan at 2024/06/03 23:35
// leetgo: 1.4.7
// https://leetcode.cn/problems/distribute-candies-to-people/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    int firstRoundTotal = (1 + num_people) * num_people / 2;

    vector<int> ans(num_people, 0);
    int temp;
    for (int j = 0; candies > 0; j++) {
      for (int i = 0; i < num_people; i++) {
        temp = min(candies, j * num_people + i + 1);
        ans[i] += temp;
        candies -= temp;
      }
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int candies;
  LeetCodeIO::scan(cin, candies);
  int num_people;
  LeetCodeIO::scan(cin, num_people);

  Solution *obj = new Solution();
  auto res = obj->distributeCandies(candies, num_people);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
