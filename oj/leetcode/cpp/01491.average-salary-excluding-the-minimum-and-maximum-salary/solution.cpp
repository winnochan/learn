// Created by WinnoChan at 2024/05/03 22:43
// leetgo: 1.4.5
// https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  double average(vector<int> &salary) {
    long long total = 0;
    int minVal = salary[0];
    int maxVal = salary[0];
    for (const auto &val : salary) {
      total += val;
      minVal = min(minVal, val);
      maxVal = max(maxVal, val);
    }
    return double(total - minVal - maxVal) / (salary.size() - 2);
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> salary;
  LeetCodeIO::scan(cin, salary);

  Solution *obj = new Solution();
  auto res = obj->average(salary);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
