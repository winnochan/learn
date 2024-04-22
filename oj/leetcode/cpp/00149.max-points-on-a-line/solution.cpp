// Created by WinnoChan at 2024/04/23 05:28
// leetgo: 1.4.5
// https://leetcode.cn/problems/max-points-on-a-line/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxAns = 0;
        unordered_map<long long, unordered_set<long long>> table{};

        for (int i = 0; i < n - 1; ++i) {
            int ans = 0;
            table.clear();

            for (int j = i + 1; j < n; ++j) {
                auto s = points[i];
                auto t = points[j];
                int dx = s[0] - t[0];
                int dy = s[1] - t[1];
                int div = gcd(abs(dx), abs(dy));
                if (!dx) {
                    dy = 1;
                } else if (!dy) {
                    dx = 1;
                } else {
                    if (dx < 0) {
                        dx /= -div;
                        dy /= -div;
                    } else {
                        dx /= div;
                        dy /= div;
                    }
                }

                long long key = hash(dx, dy);
                long long p1 = hash(s[0], s[1]);
                long long p2 = hash(t[0], t[1]);

                table[key].insert(p1);
                table[key].insert(p2);
            }

            for (const auto& pair : table) {
                ans = max(ans, int(pair.second.size()));
            }
            maxAns = max(maxAns, ans);
        }

        return maxAns;
    }

    long long hash(long long x, long long y) {
        return (x + 10000) * 100000 + (y + 10000);
    }

    int gcd(int n, int m) {
        if (!m)
            return n;
        if (n < m)
            return gcd(m, n);
        return gcd(m, n % m);
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> points;
  LeetCodeIO::scan(cin, points);

  Solution *obj = new Solution();
  auto res = obj->maxPoints(points);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
