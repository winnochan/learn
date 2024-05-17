// Created by WinnoChan at 2024/05/18 01:42
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<long long> psum(n, nums[0]);
        for (int i = 1; i < n; i++) {
            psum[i] = nums[i] + psum[i - 1];
        }
        int l, r;
        long long t;
        vector<long long> ans(m, 0);
        for (int i = 0; i < m; i++) {
            t = queries[i];
            l = bs(nums, queries[i]);
            r = bs(nums, queries[i] + 1);
            ans[i] += l * t - (l > 0 ? psum[l - 1] : 0); // 计算左部分
            ans[i] += psum[n - 1] - (r > 0 ? psum[r - 1] : 0) - t * (n - r);
        }

        return ans;
    }

    int bs(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] >= val) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  vector<int> queries;
  LeetCodeIO::scan(cin, queries);

  Solution *obj = new Solution();
  auto res = obj->minOperations(nums, queries);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
