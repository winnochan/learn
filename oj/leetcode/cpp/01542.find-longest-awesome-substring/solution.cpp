// Created by WinnoChan at 2024/05/22 23:50
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-longest-awesome-substring/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    static constexpr int BIT_MAX = 1 << 10;

public:
    int longestAwesome(string s) {
        int n = s.size();
        int ans = 1;
        vector<int> idx(BIT_MAX + 1, -1);
        int pxor = 1 << (s[0] - '0');
        idx[pxor] = 0;
        for (int i = 1; i < n; i++) {
            pxor ^= 1 << (s[i] - '0');
            if (idx[pxor] < 0) {
                idx[pxor] = i;
            }
            if (!pxor || !(pxor ^ (pxor & -pxor))) {
                // 前缀即可组成回文
                ans = i + 1;
                continue;
            }
            if (idx[pxor] >= 0) {
                // 偶数回文
                ans = max(ans, i - idx[pxor]);
            }
            int mask = 1;
            while (mask < BIT_MAX) {
                // 奇数回文
                int temp = mask ^ pxor;
                if (idx[temp] >= 0) {
                    ans = max(ans, i - idx[temp]);
                }
                mask <<= 1;
            }
        }

        return ans;
    }

    void printVec(vector<int>& vec) {
        cout << "=========================\n";
        for (const auto& val: vec) {
            cout << val << ' ';
        }
        cout << "\n---------------------------\n";
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->longestAwesome(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
