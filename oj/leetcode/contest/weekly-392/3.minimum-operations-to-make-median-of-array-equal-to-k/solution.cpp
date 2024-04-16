// Created by WinnoChan at 2024/04/17 03:00
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-operations-to-make-median-of-array-equal-to-k/
// https://leetcode.cn/contest/weekly-contest-392/problems/minimum-operations-to-make-median-of-array-equal-to-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->minOperationsToMakeMedianK(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
