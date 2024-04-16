// Created by WinnoChan at 2024/04/17 03:03
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/
// https://leetcode.cn/contest/biweekly-contest-128/problems/minimum-time-to-visit-disappearing-nodes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);
	vector<vector<int>> edges;
	LeetCodeIO::scan(cin, edges);
	vector<int> disappear;
	LeetCodeIO::scan(cin, disappear);

	Solution *obj = new Solution();
	auto res = obj->minimumTime(n, edges, disappear);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
