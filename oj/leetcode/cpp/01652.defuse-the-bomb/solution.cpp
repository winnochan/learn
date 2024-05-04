// Created by WinnoChan at 2024/05/05 03:13
// leetgo: 1.4.5
// https://leetcode.cn/problems/defuse-the-bomb/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) {
            return ans;
        }
        vector<int>& psum = code;
        // vector<int> psum(n, code[0]);
        for (int i = 1; i < n; i++) {
            psum[i] = psum[i - 1] + code[i];
        }
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                if (i + k < n) {
                    ans[i] = psum[i + k] - psum[i];
                } else {
                    ans[i] = psum[n - 1] - psum[i] + psum[(i + k) % n];
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (i + k == 0) {
                    ans[i] = psum[i - 1];
                } else if (i + k > 0) {
                    ans[i] = psum[i - 1] - psum[i + k - 1];
                } else if (i >= 1) {
                    ans[i] = psum[i - 1] + (psum[n - 1] - psum[n - 1 + i + k]);
                } else {
                    ans[i] = psum[n - 1] - psum[n - 1 + k];
                }
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> code;
  LeetCodeIO::scan(cin, code);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->decrypt(code, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
