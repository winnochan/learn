// Created by WinnoChan at 2024/04/24 23:14
// leetgo: 1.4.5
// https://leetcode.cn/problems/simplify-path/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  string simplifyPath(string path) {
    stringstream ss(path);
    deque<string> deq;
    string part;
    while (getline(ss, part, '/')) {
      // cout << "->" << part << '\n';
      if (part == "") {
        continue;
      }
      // cout << "->" << part << '\n';
      if (part == "..") {
        if (deq.size() >= 1) {
          deq.pop_back();
        }
      } else if (part != ".") {
        deq.push_back(part);
      }
    }
    string ans = "";
    for (const auto &s : deq) {
      ans += "/" + s;
      // cout << "->" << ans << '\n';
    }
    return ans == "" ? "/" : ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string path;
  LeetCodeIO::scan(cin, path);

  Solution *obj = new Solution();
  auto res = obj->simplifyPath(path);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
