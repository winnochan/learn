// Created by WinnoChan at 2024/05/01 02:24
// leetgo: 1.4.5
// https://leetcode.cn/problems/total-cost-to-hire-k-workers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        candidates = min(candidates, n);
        auto b = costs.begin();
        auto e = costs.end();
        auto rb = costs.rbegin();
        priority_queue<int, vector<int>, greater<int>> ppq;
        priority_queue<int, vector<int>, greater<int>> spq;
        if (2 * candidates >= n) {
            ppq = priority_queue<int, vector<int>, greater<int>>(b, e);
        } else {
            ppq = priority_queue<int, vector<int>, greater<int>>(b, b + candidates);
            spq = priority_queue<int, vector<int>, greater<int>>(rb, rb + candidates);
        }

        int left = candidates;
        int right = n - candidates - 1;
        long long ans = 0;
        int pt;
        int st;
        for (int i = 0; i < k; i++) {
            pt = ppq.empty() ? 1e9 : ppq.top();
            st = spq.empty() ? 1e9 : spq.top();

            if (pt == st) {
                if (left <= right && costs[left] > costs[right]) {
                    ans += st;
                    spq.pop();
                    if (left <= right) {
                        spq.push(costs[right--]);
                    }
                } else {
                    ans += pt;
                    ppq.pop();
                    if (left <= right) {
                        ppq.push(costs[left++]);
                    }
                }
            } else if (pt < st) {
                ans += pt;
                ppq.pop();
                if (left <= right) {
                    ppq.push(costs[left++]);
                }
            } else {
                ans += st;
                spq.pop();
                if (left <= right) {
                    spq.push(costs[right--]);
                }
            }

            cout << ans << ' ' << min(pt, st) << '\n';
        }

        return ans;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> costs;
  LeetCodeIO::scan(cin, costs);
  int k;
  LeetCodeIO::scan(cin, k);
  int candidates;
  LeetCodeIO::scan(cin, candidates);

  Solution *obj = new Solution();
  auto res = obj->totalCost(costs, k, candidates);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
