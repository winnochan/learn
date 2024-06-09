// Created by WinnoChan at 2024/06/10 01:37
// leetgo: 1.4.7
// https://leetcode.cn/problems/boats-to-save-people/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end(), greater<int>());
    int n = people.size();
    int ans = 0;
    vector<int> vals{};
    for (const auto &v : people) {
      if (vals.size() && v + vals.back() <= limit) {
        ans++;
        vals.pop_back();
      } else {
        vals.emplace_back(v);
      }
    }
    ans += vals.size();
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> people;
  LeetCodeIO::scan(cin, people);
  int limit;
  LeetCodeIO::scan(cin, limit);

  Solution *obj = new Solution();
  auto res = obj->numRescueBoats(people, limit);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
