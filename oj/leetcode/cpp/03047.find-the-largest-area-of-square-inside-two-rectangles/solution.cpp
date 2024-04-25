// Created by WinnoChan at 2024/04/26 00:39
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-the-largest-area-of-square-inside-two-rectangles/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, getIntersectedArea(bottomLeft, topRight, i, j));
            }
        }
        return ans;
    }

    long long getIntersectedArea(vector<vector<int>>& bottomLeft,
                                 vector<vector<int>>& topRight, int i, int j) {
        auto ixbl = bottomLeft[i][0];
        auto iybl = bottomLeft[i][1];
        auto ixtr = topRight[i][0];
        auto iytr = topRight[i][1];
        auto jxbl = bottomLeft[j][0];
        auto jybl = bottomLeft[j][1];
        auto jxtr = topRight[j][0];
        auto jytr = topRight[j][1];
        if (jxbl >= ixtr || ixbl >= jxtr) {
            // x轴不想交
            return 0;
        }
        if (jybl >= iytr || iybl >= jytr) {
            // y轴不想交
            return 0;
        }
        auto dx = min(ixtr, jxtr) - max(ixbl, jxbl);
        auto dy = min(iytr, jytr) - max(iybl, jybl);
        // printf("i=%d,j=%d,dx=%d,dy=%d\n", i, j, dx, dy);
        long long dm = min(dx, dy);
        return dm * dm;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> bottomLeft;
  LeetCodeIO::scan(cin, bottomLeft);
  vector<vector<int>> topRight;
  LeetCodeIO::scan(cin, topRight);

  Solution *obj = new Solution();
  auto res = obj->largestSquareArea(bottomLeft, topRight);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
