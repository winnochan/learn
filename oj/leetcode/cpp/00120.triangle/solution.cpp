// Created by WinnoChan at 2024/04/21 02:45
// leetgo: 1.4.5
// https://leetcode.cn/problems/triangle/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    return dp1d(triangle);
  }

  int dp1d(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n, 1e8);
    dp[0] = triangle[0][0];

    // printVec(dp);
    int temp = 0;
    for (int i = 1; i < n - 1; i++) {
      for (int j = i; j >= 0; j--) {
        temp = 1e8;
        if (j > 0) {
          temp = min(temp, dp[j - 1] + triangle[i][j]);
        }
        if (j < i) {
          temp = min(temp, dp[j] + triangle[i][j]);
        }
        dp[j] = temp;
      }
      // printVec(dp);
    }
    int ans = 1e8;
    for (int j = n - 1; j >= 0; j--) {
      temp = 1e8;
      if (j > 0) {
        temp = min(temp, dp[j - 1] + triangle[n - 1][j]);
      }
      if (j < n - 1) {
        temp = min(temp, dp[j] + triangle[n - 1][j]);
      }
      if (temp == 1e8) {
        temp = triangle[n - 1][j];
      }
      dp[j] = temp;
      ans = min(ans, temp);
    }
    // printVec(dp);

    return ans;
  }

  int dp2d(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<vector<int>> dp(triangle);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i][j] = 1e8;
        if (j > 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
        }
        if (j < i) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
        }
      }
    }
    // print2DVec(dp);

    int ans = 1e8;
    for (const auto val : dp[n - 1]) {
      ans = min(ans, val);
    }

    return ans;
  }

  void printVec(vector<int>& vec) {
    for (const auto v : vec) {
      cout << v << ' ';
    }
    cout << endl;
  }

  void print2DVec(vector<vector<int>>& vec) {
    for (const auto v : vec) {
      for (const auto u : v) {
        cout << u << ' ';
      }
      cout << endl;
    }
    cout << "===================" << endl;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> triangle;
  LeetCodeIO::scan(cin, triangle);

  Solution *obj = new Solution();
  auto res = obj->minimumTotal(triangle);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
