// Created by WinnoChan at 2024/06/14 03:04
// leetgo: 1.4.7
// https://leetcode.cn/problems/visit-array-positions-to-maximize-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();

        int oi = -1;
        int ei = -1;
        long long ov = INT_MIN;
        long long ev = INT_MIN;
        if (nums[0] & 1) {
            ov = nums[0];
            oi = 0;
        } else {
            ev = nums[0];
            ei = 0;
        }

        for (int i = 1; i < n; ++i) {
            if (nums[i] & 1) {
                ov = max(ov + nums[i], ev + nums[i] - x);
                oi = i;
            } else {
                ev = max(ev + nums[i], ov + nums[i] - x);
                ei = i;
            }
        }
        return max(ov, ev);
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int x;
  LeetCodeIO::scan(cin, x);

  Solution *obj = new Solution();
  auto res = obj->maxScore(nums, x);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
