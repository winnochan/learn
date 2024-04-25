// Created by WinnoChan at 2024/04/26 02:13
// leetgo: 1.4.5
// https://leetcode.cn/problems/count-complete-tree-nodes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh == rh) {
      return (1 << lh) + countNodes(root->right);
    } else {
      return (1 << rh) + countNodes(root->left);
    }
  }

  int height(TreeNode *root) {
    int ans = 0;
    while (root) {
      ans++;
      root = root->left;
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode* root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->countNodes(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
