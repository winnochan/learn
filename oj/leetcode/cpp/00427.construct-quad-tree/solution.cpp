// Created by WinnoChan at 2024/05/01 23:30
// leetgo: 1.4.5
// https://leetcode.cn/problems/construct-quad-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] +
                                          prefixSum[i + 1][j] -
                                          prefixSum[i][j] + grid[i][j];
            }
        }
        return helper(prefixSum, 0, 0, n, n);
    }

    // 区间是左开右闭
    Node* helper(vector<vector<int>>& prefixSum, int lx, int ly, int rx,
                 int ry) {
        Node* root = new Node();
        if (lx >= rx || ly >= ry) {
            return root;
        }
        int matSum = prefixSum[rx][ry] + prefixSum[lx][ly] - prefixSum[lx][ry] -
                     prefixSum[rx][ly];
        if (!matSum || matSum == (rx - lx) * (ry - ly)) {
            // 符合叶子节点条件
            root->isLeaf = true;
            root->val = !!matSum;
            // printf("lx=%d,ly=%d,rx=%d,ry=%d,sum=%d\n", lx, ly, rx, ry, matSum);
        } else {
            int mx = lx + ((rx - lx) >> 1);
            int my = ly + ((ry - ly) >> 1);
            root->topLeft = helper(prefixSum, lx, ly, mx, my);
            root->topRight = helper(prefixSum, lx, my, mx, ry);
            root->bottomLeft = helper(prefixSum, mx, ly, rx, my);
            root->bottomRight = helper(prefixSum, mx, my, rx, ry);
        }
        return root;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> grid;
  LeetCodeIO::scan(cin, grid);

  Solution *obj = new Solution();
  auto res = obj->construct(grid);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
