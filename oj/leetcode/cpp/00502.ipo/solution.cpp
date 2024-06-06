// Created by WinnoChan at 2024/06/06 23:32
// leetgo: 1.4.7
// https://leetcode.cn/problems/ipo/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> ids(n, 0);
        for (int i = 1; i < n; i++) {
            ids[i] = i;
        }

        sort(ids.begin(), ids.end(), [&capital](int a, int b) -> bool {
            return capital[a] < capital[b];
        });

        priority_queue<int, vector<int>, function<bool(int, int)>> pq([&profits](int a, int b) -> bool {
            return profits[a] < profits[b];
        });

        int i = 0;
        int c = 0;
        while (i < n && c < k) {
            while (i < n && capital[ids[i]] <= w) {
                pq.emplace(ids[i++]);
            }
            if (!pq.size()) {
                break;
            }
            c++;
            w += profits[pq.top()];
            pq.pop();
        }
        while (c < k && pq.size()) {
            c++;
            w += profits[pq.top()];
            pq.pop();
        }

        return w;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int k;
  LeetCodeIO::scan(cin, k);
  int w;
  LeetCodeIO::scan(cin, w);
  vector<int> profits;
  LeetCodeIO::scan(cin, profits);
  vector<int> capital;
  LeetCodeIO::scan(cin, capital);

  Solution *obj = new Solution();
  auto res = obj->findMaximizedCapital(k, w, profits, capital);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
