// Created by WinnoChan at 2024/04/22 05:58
// leetgo: 1.4.5
// https://leetcode.cn/problems/combination-sum-iv/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return dp(nums, target);
    }

    int dfs(vector<int>& nums, int target) {
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
        int ans = 0;

        for (const auto val : nums) {
            ans += dfs(nums, target - val);
        }

        return ans;
    }

    int dp(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (const auto val : nums) {
                if (val > i) {
                    break;
                }
                dp[i] += dp[i - val];
            }
        }

        return dp[target];
    }

    void printVec(vector<int>& vec) {
        for (const auto& val : vec) {
            cout << val << ' ';
        }
        cout << endl;
    }

    void printVec2D(vector<vector<int>>& mat) {
        for (const auto& vec : mat) {
            for (const auto& val : vec) {
                cout << val << ' ';
            }
            cout << endl;
        }
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int target;
  LeetCodeIO::scan(cin, target);

  Solution *obj = new Solution();
  auto res = obj->combinationSum4(nums, target);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
