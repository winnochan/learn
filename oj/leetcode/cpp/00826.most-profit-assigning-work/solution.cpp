// Created by WinnoChan at 2024/05/17 01:34
// leetgo: 1.4.5
// https://leetcode.cn/problems/most-profit-assigning-work/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<int> ids(n, 0);
        for (int i = 1; i < n; i++) {
            ids[i] = i;
        }
        sort(ids.begin(), ids.end(), [&](int a, int b) -> bool {
            if (difficulty[a] < difficulty[b]) {
                return true;
            }
            if (difficulty[a] == difficulty[b]) {
                return profit[a] > profit[b];
            }
            return false;
        });
        vector<int> pmax(n, profit[ids[0]]);
        for (int i = 1; i < n; i++) {
            pmax[i] = max(pmax[i - 1], profit[ids[i]]);
        }
        // printVec(pmax);

        int ans = 0, temp;
        for (const auto& upper: worker) {
            temp = findMaxIdBlow(difficulty, ids, upper);
            // cout << temp << ' ' << ans << '\n';
            if (temp < 0) {
                continue;
            }
            ans += pmax[temp];
        }

        return ans;
    }

    int findMaxIdBlow(vector<int>& difficulty, vector<int>& ids, int upper) {
        int l = 0;
        int r = difficulty.size() - 1;
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (difficulty[ids[m]] == upper) {
                return m;
            } else if (difficulty[ids[m]] > upper) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }

    void printVec(vector<int>& vec) {
        cout << "==========================\n";
        for (const auto& val : vec) {
            cout << val << '\t';
        }
        cout << '\n';
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> difficulty;
  LeetCodeIO::scan(cin, difficulty);
  vector<int> profit;
  LeetCodeIO::scan(cin, profit);
  vector<int> worker;
  LeetCodeIO::scan(cin, worker);

  Solution *obj = new Solution();
  auto res = obj->maxProfitAssignment(difficulty, profit, worker);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
