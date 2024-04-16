// Created by WinnoChan at 2024/04/17 03:01
// leetgo: 1.4.5
// https://leetcode.cn/problems/kth-smallest-amount-with-single-denomination-combination/
// https://leetcode.cn/contest/weekly-contest-393/problems/kth-smallest-amount-with-single-denomination-combination/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> coins;
	LeetCodeIO::scan(cin, coins);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->findKthSmallest(coins, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
