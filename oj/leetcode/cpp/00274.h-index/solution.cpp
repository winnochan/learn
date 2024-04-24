// Created by WinnoChan at 2024/04/24 11:07
// leetgo: 1.4.5
// https://leetcode.cn/problems/h-index/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int hIndex(vector<int> &citations) {
    // 论文数
    int totalPaper = citations.size();

    constexpr int val_max = 1001;
    int cnt[val_max]{0};
    for (const auto &c : citations) {
      cnt[c] += 1;
    }
    int ans = 0;
    for (int i = 0; i < val_max; i++) {
      if (totalPaper >= i) {
        ans = i;
      } else {
        break;
      }
      totalPaper -= cnt[i];
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> citations;
  LeetCodeIO::scan(cin, citations);

  Solution *obj = new Solution();
  auto res = obj->hIndex(citations);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
