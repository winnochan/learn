// Created by WinnoChan at 2024/05/11 02:05
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int M = 'M';
        int P = 'P';
        int G = 'G';

        int idx[128] { 0 };
        idx[P] = 1;
        idx[G] = 2;

        int n = garbage.size();
        vector<vector<int>> cnt(n, vector<int>(3, 0));
        int mmax = 0;
        int pmax = 0;
        int gmax = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            const auto& str = garbage[i];
            for (const auto& chr : str) {
                cnt[i][idx[chr]]++;
            }
            if (cnt[i][idx[M]] > 0) {
                mmax = i;
            }
            if (cnt[i][idx[P]] > 0) {
                pmax = i;
            }
            if (cnt[i][idx[G]] > 0) {
                gmax = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i < mmax) {
                ans += travel[i];
            }
            if (i < pmax) {
                ans += travel[i];
            }
            if (i < gmax) {
                ans += travel[i];
            }
            ans += cnt[i][idx[M]] + cnt[i][idx[P]] + cnt[i][idx[G]];
        }
        return ans;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> garbage;
  LeetCodeIO::scan(cin, garbage);
  vector<int> travel;
  LeetCodeIO::scan(cin, travel);

  Solution *obj = new Solution();
  auto res = obj->garbageCollection(garbage, travel);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
