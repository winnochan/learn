// Created by WinnoChan at 2024/04/17 03:01
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-sum-of-values-by-dividing-array/
// https://leetcode.cn/contest/weekly-contest-393/problems/minimum-sum-of-values-by-dividing-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	vector<int> andValues;
	LeetCodeIO::scan(cin, andValues);

	Solution *obj = new Solution();
	auto res = obj->minimumValueSum(nums, andValues);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
