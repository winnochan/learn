// Created by WinnoChan at 2024/04/22 07:50
// leetgo: 1.4.5
// https://leetcode.cn/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> q(1, root);
        int left = 0;
        int right = q.size();

        vector<double> ans;
        while (left < right) {
            double total = 0;
            double count = 0;
            for (int i = left; i < right; ++i) {
                auto node = q[i];
                total += node->val;
                count++;
                if (node->left) {
                    q.push_back(node->left);
                }
                if (node->right) {
                    q.push_back(node->right);
                }
            }
            left = right;
            right = q.size();
            ans.push_back(total / count);
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
  auto res = obj->averageOfLevels(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
