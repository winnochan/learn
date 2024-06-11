// Created by WinnoChan at 2024/06/12 00:20
// leetgo: 1.4.7
// https://leetcode.cn/problems/account-balance-after-rounded-purchase/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int accountBalanceAfterPurchase(int purchaseAmount) {
    return 100 - (purchaseAmount + 5) / 10 * 10;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int purchaseAmount;
  LeetCodeIO::scan(cin, purchaseAmount);

  Solution *obj = new Solution();
  auto res = obj->accountBalanceAfterPurchase(purchaseAmount);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
