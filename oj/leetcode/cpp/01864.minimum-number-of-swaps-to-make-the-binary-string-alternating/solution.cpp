// Created by WinnoChan at 2024/04/16 22:25
// leetgo: 1.4.5
// https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

#include <bits/stdc++.h>
#include "LC_IO.h"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=begin

class Solution {
public:
  int minSwaps(string s) {
    auto ones = 0;
    auto oddOnes = 0;
    auto evenOnes = 0;
    auto len = s.length();
    for (auto i = 0; i < len; ++i) {
      if (s[i] == '1') {
        ones++;
        if (i % 2) {
          oddOnes++;
        } else {
          evenOnes++;
        }
      }
    }
    if (len % 2) {
      // 奇数时, 有两种可能, 1的数量可以是 (len / 2) 或者 (1 + len / 2)
      if (ones == len / 2) {
        // 需要把所有偶数位的1放到奇数位
        return evenOnes;
      } else if (ones == 1 + (len / 2)) {
        // 需要把所有奇数位的1放到偶数位
        return oddOnes;
      } else {
        return -1;
      }
    } else {
      // 偶数时, 1的数量必须刚好是一半才符合要求
      return ones * 2 != len ? -1 : std::min(oddOnes, evenOnes);
    }
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->minSwaps(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
