// Created by WinnoChan at 2024/04/17 03:01
// leetgo: 1.4.5
// https://leetcode.cn/problems/maximum-prime-difference/
// https://leetcode.cn/contest/weekly-contest-393/problems/maximum-prime-difference/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->maximumPrimeDifference(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
