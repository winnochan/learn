// Created by WinnoChan at 2024/05/05 05:00
// leetgo: 1.4.5
// https://leetcode.cn/problems/keys-and-rooms/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    vector<bool> vis(n, false);
    vis[0] = true;
    vector<int> sta(n, 0);
    int left = 0, right = 1, temp, i, u;
    while (left < right) {
      temp = right;
      for (i = left; i < temp; i++) {
        u = sta[i];
        for (const auto &v : rooms[u]) {
          if (vis[v]) {
            continue;
          }
          vis[v] = true;
          sta[right++] = v;
        }
      }
      left = temp;
    }
    return right == n;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> rooms;
  LeetCodeIO::scan(cin, rooms);

  Solution *obj = new Solution();
  auto res = obj->canVisitAllRooms(rooms);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
