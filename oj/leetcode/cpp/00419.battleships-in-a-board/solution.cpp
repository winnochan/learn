// Created by WinnoChan at 2024/06/11 02:16
// leetgo: 1.4.7
// https://leetcode.cn/problems/battleships-in-a-board/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int countBattleships(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();

    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] != 'X') {
          continue;
        }
        int c = (i + 1 < m && board[i + 1][j] == 'X') ? 1 : 0;
        c += (j + 1 < n && board[i][j + 1] == 'X') ? 1 : 0;
        if (c) {
          continue;
        }
        ans++;
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<char>> board;
  LeetCodeIO::scan(cin, board);

  Solution *obj = new Solution();
  auto res = obj->countBattleships(board);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
