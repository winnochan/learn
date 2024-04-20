// Created by WinnoChan at 2024/04/21 07:21
// leetgo: 1.4.5
// https://leetcode.cn/problems/ransom-note/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int src[128]{0};
    int dst[128]{0};

    for (const auto c : ransomNote) {
      src[int(c)] += 1;
    }
    for (const auto c : magazine) {
      dst[int(c)] += 1;
    }
    for (int i = 0; i < 128; i++) {
      if (src[i] > dst[i]) return false;
    }
    return true;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string ransomNote;
  LeetCodeIO::scan(cin, ransomNote);
  string magazine;
  LeetCodeIO::scan(cin, magazine);

  Solution *obj = new Solution();
  auto res = obj->canConstruct(ransomNote, magazine);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
