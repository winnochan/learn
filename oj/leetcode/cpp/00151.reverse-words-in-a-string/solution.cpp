// Created by WinnoChan at 2024/04/20 23:36
// leetgo: 1.4.5
// https://leetcode.cn/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  string reverseWords(string s) {
    vector<string> vec = toVector(s, ' ');

    string ans = "";
    for (int i = vec.size() - 1; i >= 0; --i) {
      ans += vec[i];
      if (i > 0) {
        ans += " ";
      }
    }
    return ans;
  }

  vector<string> toVector(string& s, char del) {
    stringstream ss(s);
    string word;
    vector<string> vec{};

    while (!ss.eof()) {
      getline(ss, word, del);
      if (!word.size()) continue;
      vec.push_back(word);
    }
    return vec;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution *obj = new Solution();
  auto res = obj->reverseWords(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
