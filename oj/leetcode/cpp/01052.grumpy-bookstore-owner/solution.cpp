// Created by WinnoChan at 2024/04/23 04:53
// leetgo: 1.4.5
// https://leetcode.cn/problems/grumpy-bookstore-owner/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    // 带条件的滑动窗口最大值
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        // 修正minutes不超过N数组长度
        minutes = min(n, minutes);

        int ans = 0;
        int sum = 0;
        int mi = minutes - 1;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i]) {
                // 滑动窗口和
                sum += customers[i];
            } else {
                ans += customers[i];
            }
        }
        int temp = sum;
        for (int i = minutes, left = 0; i < n; ++i, ++left) {
            if (grumpy[left]) {
                temp -= customers[left];
            }
            if (grumpy[i]) {
                temp += customers[i];
            } else {
                ans += customers[i];
            }
            if (temp > sum) {
                sum = temp;
                mi = i;
            }
        }
        for (int i = mi - minutes + 1; i <= mi; ++i) {
            if (grumpy[i]) {
                ans += customers[i];
            }
        }

        return ans;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> customers;
  LeetCodeIO::scan(cin, customers);
  vector<int> grumpy;
  LeetCodeIO::scan(cin, grumpy);
  int minutes;
  LeetCodeIO::scan(cin, minutes);

  Solution *obj = new Solution();
  auto res = obj->maxSatisfied(customers, grumpy, minutes);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
