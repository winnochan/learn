// Created by WinnoChan at 2024/04/24 06:04
// leetgo: 1.4.5
// https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/

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
    int amountOfTime(TreeNode* root, int start) {
      constexpr int n = 1e5 + 1;

      vector<vector<int>> graph(n);
      createGraph(graph, root);

      array<int, n> vis = { 0 };
      array<int, n> que = { start };
      vis[start] = 1;

      int left = 0;
      int right = 1;
      int ans = 0;
      while (left < right) {
        int levelRight = right;
        int flag = 0;
        for (int i = left; i < levelRight; i++) {
          int node = que[i];
          vis[node] = 1;
          for (auto & other: graph[node]) {
            if (vis[other]) continue;
            vis[other] = 1;
            que[right++] = other;
            flag = 1;
          }
        }
        left = levelRight;
        if (flag) {
          ans++;
        }
      }

      return ans;
    }

    void createGraph(vector<vector<int>>& graph, TreeNode* root) {
      if (!root) return;
      if (root->left) {
        graph[root->val].push_back(root->left->val);
        graph[root->left->val].push_back(root->val);
        createGraph(graph, root->left);
      }
      if (root->right) {
        graph[root->val].push_back(root->right->val);
        graph[root->right->val].push_back(root->val);
        createGraph(graph, root->right);
      }
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode* root;
  LeetCodeIO::scan(cin, root);
  int start;
  LeetCodeIO::scan(cin, start);

  Solution *obj = new Solution();
  auto res = obj->amountOfTime(root, start);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
