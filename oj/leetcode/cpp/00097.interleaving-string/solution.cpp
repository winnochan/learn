// Created by WinnoChan at 2024/05/01 20:18
// leetgo: 1.4.5
// https://leetcode.cn/problems/interleaving-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        int cnt[128] = {0};
        for (const auto& chr : s1) {
            cnt[int(chr)]++;
        }
        for (const auto& chr : s2) {
            cnt[int(chr)]++;
        }
        for (const auto& chr : s3) {
            cnt[int(chr)]--;
            if (cnt[int(chr)] < 0) {
                return false;
            }
        }
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        // printMat(dp);

        return dp[m][n];
    }

    void printMat(vector<vector<bool>>& mat) {
        for (const auto& vec : mat) {
            for (const auto& val : vec) {
                cout << val << ' ';
            }
            cout << '\n';
        }
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s1;
  LeetCodeIO::scan(cin, s1);
  string s2;
  LeetCodeIO::scan(cin, s2);
  string s3;
  LeetCodeIO::scan(cin, s3);

  Solution *obj = new Solution();
  auto res = obj->isInterleave(s1, s2, s3);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
