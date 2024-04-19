// Created by WinnoChan at 2024/04/20 07:37
// leetgo: 1.4.5
// https://leetcode.cn/problems/valid-palindrome/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
      while (left < right && !isAscii(s[left])) {
        left++;
      }
      while (left < right && !isAscii(s[right])) {
        right--;
      }
      if (tolower(s[left]) == tolower(s[right])) {
        left++;
        right--;
      } else {
        return false;
      }
    }
    return right - left <= 0;
  }

  bool isAscii(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->isPalindrome(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
