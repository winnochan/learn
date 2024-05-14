// Created by WinnoChan at 2024/05/15 01:33
// leetgo: 1.4.5
// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans{};
        vector<vector<TreeNode*>> que{};
        if (!root) {
            return {};
        }
        ans.push_back({root->val});
        que.push_back({root});
        int level = 0;
        while (level < que.size()) {
            vector<int> vals{};
            vector<TreeNode*> nodes{};
            for (const auto node : que[level]) {
                if (node->left) {
                    nodes.push_back(node->left);
                    vals.push_back(node->left->val);
                }
                if (node->right) {
                    nodes.push_back(node->right);
                    vals.push_back(node->right->val);
                }
            }
            if (vals.size()) {
                que.push_back(nodes);
                ans.push_back(vals);
            }
            level++;
        }
        reverse(ans.begin(), ans.end());

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
  auto res = obj->levelOrderBottom(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
