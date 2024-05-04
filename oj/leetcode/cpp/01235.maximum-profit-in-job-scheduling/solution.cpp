// Created by WinnoChan at 2024/05/04 23:21
// leetgo: 1.4.5
// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        unordered_set<int> tpSet;
        for (int i = 0; i < n; i++) {
            tpSet.insert(startTime[i]);
            tpSet.insert(endTime[i]);
        }
        vector<int> tpVec(tpSet.begin(), tpSet.end());
        int m = tpVec.size();

        sort(tpVec.begin(), tpVec.end());
        // printVec(tpVec);
        unordered_map<int, int> tpMap;
        for (int i = 0; i < m; i++) {
            tpMap[tpVec[i]] = i + 1;
        }
        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int a, int b) -> bool {
            if (endTime[a] == endTime[b]) {
                return startTime[a] > startTime[b];
            }
            return endTime[a] < endTime[b];
        });
        int maxEnd = tpMap[endTime[idx.back()]];
        vector<int> dp(maxEnd + 1, 0);
        // printVec(idx);
        int ci = 0;
        for (int i = 1; i <= maxEnd; i++) {
            if (tpMap[endTime[idx[ci]]] > i) {
                dp[i] = max(dp[i - 1], dp[i]);
                // printVec(dp);
                continue;
            }
            while (ci < n && tpMap[endTime[idx[ci]]] <= i) {
                dp[i] =
                    max(dp[i - 1], max(dp[i], dp[tpMap[startTime[idx[ci]]]] +
                                                  profit[idx[ci]]));
                // cout << i << "-" << idx[ci] << ": ";
                // printVec(dp);
                ci++;
            }
        }
        return dp[maxEnd];
    }

    void printVec(vector<int>& vec) {
        for (const auto& val : vec) {
            cout << val << ' ';
        }
        cout << '\n';
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> startTime;
  LeetCodeIO::scan(cin, startTime);
  vector<int> endTime;
  LeetCodeIO::scan(cin, endTime);
  vector<int> profit;
  LeetCodeIO::scan(cin, profit);

  Solution *obj = new Solution();
  auto res = obj->jobScheduling(startTime, endTime, profit);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
