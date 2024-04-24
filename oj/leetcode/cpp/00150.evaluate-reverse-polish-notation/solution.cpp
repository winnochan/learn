// Created by WinnoChan at 2024/04/25 01:29
// leetgo: 1.4.5
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> numq;
        for (const auto& t: tokens) {
            if (t == "+") {
                int right = numq.back();
                numq.pop_back();
                int left = numq.back();
                numq.pop_back();
                numq.push_back(left + right);
            } else if (t == "-") {
                int right = numq.back();
                numq.pop_back();
                int left = numq.back();
                numq.pop_back();
                numq.push_back(left - right);
            } else if (t == "*") {
                int right = numq.back();
                numq.pop_back();
                int left = numq.back();
                numq.pop_back();
                numq.push_back(left * right);
            } else if (t == "/") {
                int right = numq.back();
                numq.pop_back();
                int left = numq.back();
                numq.pop_back();
                numq.push_back(left / right);
            } else {
                numq.push_back(stoi(t));
            }
        }

        return numq[0];
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> tokens;
  LeetCodeIO::scan(cin, tokens);

  Solution *obj = new Solution();
  auto res = obj->evalRPN(tokens);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
