// Created by WinnoChan at 2024/04/17 03:03
// leetgo: 1.4.5
// https://leetcode.cn/problems/score-of-a-string/
// https://leetcode.cn/contest/biweekly-contest-128/problems/score-of-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int scoreOfString(string s) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->scoreOfString(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
