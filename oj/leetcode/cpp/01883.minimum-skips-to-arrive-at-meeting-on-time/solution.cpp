// Created by WinnoChan at 2024/04/19 23:12
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-skips-to-arrive-at-meeting-on-time/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        auto n = dist.size();
        // dp[i][j] 定义为到达第 i 个节点且跳过 j 次的情况下最小的花费时间
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, INF));

        dp[0][0] = 0;
        for (auto i = 1; i <= n; ++i) {
            for (auto j = 0; j <= n; ++j) {
                // 如果到达 i 点时没有在 i-1 点停留, 意味着在到 [i,j] 点消耗了一次休息次数
                // dp[i][j] = dp[i-1][j-1] + double(dist[i-1]) / speed
                // 如果到达 i 点时在 i-1 点停留了, 意味着到 [i,j] 点没有消耗次数
                // dp[i][j] = dp[i-1][j] + (dist[i-1] + speed - 1) / speed

                // 先计算 [i,j] 不消耗休息次数的情况
                if (i < n) {
                    dp[i][j] = ceil(dp[i-1][j] + double(dist[i-1]) / speed  - EPS);
                } else {
                    // 最后一个节点不需要停留到整点, 也不消耗次数
                    dp[i][j] = dp[i-1][j] + double(dist[i-1]) / speed;
                }

                // 再计算 [i,j] 消耗休息次数的情况
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + double(dist[i-1]) / speed);
                }
            }
            // printVec2D(dp);
            // cout << "====================" << endl;
        }
        // printVec2D(dp);
        for (auto j = 0; j <= n; ++j) {
            if (dp[n][j] <= hoursBefore + EPS) {
                return j;
            }
        }
        return -1;
    }

    void printVec2D(vector<vector<double>>& vec) {
        for (const auto& array : vec) {
            for (const auto& value : array) {
                cout << value << ' ';
            }
            cout << endl;
        }
    }

private:
    static constexpr double EPS = 1e-8;
    // static constexpr double INF = numeric_limits<double>::infinity();
    static constexpr double INF = 1e20;
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> dist;
  LeetCodeIO::scan(cin, dist);
  int speed;
  LeetCodeIO::scan(cin, speed);
  int hoursBefore;
  LeetCodeIO::scan(cin, hoursBefore);

  Solution *obj = new Solution();
  auto res = obj->minSkips(dist, speed, hoursBefore);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
