// Created by WinnoChan at 2024/04/17 03:03
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-rectangles-to-cover-points/
// https://leetcode.cn/contest/biweekly-contest-128/problems/minimum-rectangles-to-cover-points/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> points;
	LeetCodeIO::scan(cin, points);
	int w;
	LeetCodeIO::scan(cin, w);

	Solution *obj = new Solution();
	auto res = obj->minRectanglesToCoverPoints(points, w);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
