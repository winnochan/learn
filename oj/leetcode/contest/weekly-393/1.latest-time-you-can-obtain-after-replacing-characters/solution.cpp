// Created by WinnoChan at 2024/04/17 03:01
// leetgo: 1.4.5
// https://leetcode.cn/problems/latest-time-you-can-obtain-after-replacing-characters/
// https://leetcode.cn/contest/weekly-contest-393/problems/latest-time-you-can-obtain-after-replacing-characters/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string findLatestTime(string s) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->findLatestTime(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
