// Created by WinnoChan at 2024/04/17 03:00
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-cost-walk-in-weighted-graph/
// https://leetcode.cn/contest/weekly-contest-392/problems/minimum-cost-walk-in-weighted-graph/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
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
	vector<vector<int>> query;
	LeetCodeIO::scan(cin, query);

	Solution *obj = new Solution();
	auto res = obj->minimumCost(n, edges, query);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
