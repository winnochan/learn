// Created by WinnoChan at 2024/04/17 03:00
// leetgo: 1.4.5
// https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint/
// https://leetcode.cn/contest/weekly-contest-392/problems/lexicographically-smallest-string-after-operations-with-constraint/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string getSmallestString(string s, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->getSmallestString(s, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
