// Created by WinnoChan at 2024/05/19 20:46
// leetgo: 1.4.5
// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans{};
        TreeNode* node = nullptr;
        deque<TreeNode*> dq{};
        dq.push_back(root);
        while (dq.size()) {
            node = dq.front();
            dq.pop_front();

            if (!ans.size()) {
                ans += node ? to_string(node->val) : "#";
            } else {
                ans += "," + (node ? to_string(node->val) : "#");
            }
            if (node) {
                dq.push_back(node->left);
                dq.push_back(node->right);
            }
        }
        // cout << ans << '\n';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss{data};
        string temp{};

        vector<TreeNode*> q{};
        TreeNode* root = nullptr;
        TreeNode* node = nullptr;
        int i = -1;
        bool isLeft = true;
        while (getline(ss, temp, ',')) {
            // cout << temp << '\t';
            node = temp == "#" ? nullptr : new TreeNode(stoi(temp));
            if (!q.size()) {
                i = 0;
                root = node;
            } else if (isLeft) {
                q[i]->left = node;
                isLeft = false;
            } else {
                q[i++]->right = node;
                isLeft = true;
            }
            if (node) {
                q.push_back(node);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  TreeNode* root;
  LeetCodeIO::scan(cin, root);

  Solution *obj = new Solution();
  auto res = obj->Codec(root);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
