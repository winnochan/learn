// Created by WinnoChan at 2024/04/17 03:03
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/
// https://leetcode.cn/contest/biweekly-contest-128/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->numberOfSubarrays(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
