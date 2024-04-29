// Created by WinnoChan at 2024/04/29 20:46
// leetgo: 1.4.5
// https://leetcode.cn/problems/surrounded-regions/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class UF {
public:
    UF(int n) {
        root.resize(n);
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)
            return;
        root[fx] = fy;
        // if (x < y) {
        //     root[fx] = fy;
        // } else {
        //     root[fy] = fx;
        // }
    }

    int same(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int sid = row * col;
        UF uf(sid + 1);

        for (int i = 0; i < row; i++) {
            uf.merge(getId(i, 0, col), sid);
            uf.merge(getId(i, col - 1, col), sid);
        }
        for (int i = 1; i < col - 1; i++) {
            uf.merge(getId(0, i, col), sid);
            uf.merge(getId(row - 1, i, col), sid);
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (board[i][j] != 'O') {
                    continue;
                }
                if (board[i - 1][j] == 'O') {
                    uf.merge(getId(i, j, col), getId(i - 1, j, col));
                }
                if (board[i][j - 1] == 'O') {
                    uf.merge(getId(i, j, col), getId(i, j - 1, col));
                }
            }
        }
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (board[i][j] != 'O') {
                    continue;
                }
                if (uf.same(getId(i, j, col), sid)) {
                    continue;
                }
                board[i][j] = 'X';
            }
        }
    }

    int getId(int x, int y, int col) { return x * col + y; }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<char>> board;
  LeetCodeIO::scan(cin, board);

  Solution *obj = new Solution();
  auto res = obj->solve(board);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
