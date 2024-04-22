// Created by WinnoChan at 2024/04/22 16:11
// leetgo: 1.4.5
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        vector<Node*> que(1, root);
        int left = 0;
        int right = 1;

        while (left < right) {
            for (int i = left; i < right; ++i) {
                Node* node = que[i];
                if (node->left) {
                    que.push_back(node->left);
                }
                if (node->right) {
                    que.push_back(node->right);
                }
            }
            left = right;
            right = que.size();
            for (int i = left + 1; i < right; ++i) {
                que[i-1]->next = que[i];
            }
        }

        return root;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode* root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->connect(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
