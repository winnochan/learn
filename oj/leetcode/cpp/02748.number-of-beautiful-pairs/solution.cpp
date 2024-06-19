// Created by WinnoChan at 2024/06/20 02:35
// leetgo: 1.4.7
// https://leetcode.cn/problems/number-of-beautiful-pairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
  static constexpr int E8 = 1e8;
  static constexpr int E4 = 1e4;
  static constexpr int E2 = 1e2;
  static constexpr int E1 = 1e1;

public:
  int countBeautifulPairs(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (__gcd(getHighBit(nums[i]), nums[j] % 10) == 1) {
          ans++;
        }
      }
    }
    return ans;
  }

  inline int getHighBit(int n) {
    if (n >= E4) {
      n /= E4;
    }
    if (n >= E2) {
      n /= E2;
    }
    if (n >= E1) {
      n /= E1;
    }
    return n;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->countBeautifulPairs(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
