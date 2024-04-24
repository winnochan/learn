// Created by WinnoChan at 2024/04/24 13:08
// leetgo: 1.4.5
// https://leetcode.cn/problems/valid-sudoku/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<int> cnt(10, 0);
        for (int i = 0; i < n; i++) {
            cnt.assign(10, 0);
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                cnt[num]++;
                // printVec(cnt);
                if (cnt[num] > 1) return false;
            }

            cnt.assign(10, 0);
            for (int j = 0; j < n; j++) {
                if (board[j][i] == '.') continue;
                int num = board[j][i] - '0';
                cnt[num]++;
                // printVec(cnt);
                if (cnt[num] > 1) return false;
            }

        }
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                cnt.assign(10, 0);
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] == '.') continue;
                        int num = board[x][y] - '0';
                        cnt[num]++;
                        if (cnt[num] > 1) return false;
                    }
                }
                // printVec(cnt);
            }
        }
        return true;
    }

    void printVec(vector<int>& cnt) {
        for (const auto val: cnt) {
            cout << val << "";
        }
        cout << "\n===================\n";
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<char>> board;
  LeetCodeIO::scan(cin, board);

  Solution *obj = new Solution();
  auto res = obj->isValidSudoku(board);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
