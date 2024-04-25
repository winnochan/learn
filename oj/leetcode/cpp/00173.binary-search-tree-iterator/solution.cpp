// Created by WinnoChan at 2024/04/26 05:16
// leetgo: 1.4.5
// https://leetcode.cn/problems/binary-search-tree-iterator/

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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }

    int next() {
        if (!st.size()) return -1;
        TreeNode* node = st.top();
        st.pop();
        push(node->right);
        return node->val;
    }

    bool hasNext() {
        return st.size() > 0;
    }

    void push(TreeNode* root) {
        while (root) {
            st.emplace(root);
            root = root->left;
        }
    }

private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> method_names;
  LeetCodeIO::scan(cin, method_names);

  BSTIterator *obj;
  const unordered_map<string, function<void()>> methods = {
    { "BSTIterator", [&]() {
      TreeNode* root; LeetCodeIO::scan(cin, root); cin.ignore();
      obj = new BSTIterator(root);
      out_stream << "null,";
    } },
    { "next", [&]() {
      cin.ignore();
      LeetCodeIO::print(out_stream, obj->next()); out_stream << ',';
    } },
    { "hasNext", [&]() {
      cin.ignore();
      LeetCodeIO::print(out_stream, obj->hasNext()); out_stream << ',';
    } },
  };
  cin >> ws;
  out_stream << '[';
  for (auto &&method_name : method_names) {
    cin.ignore(2);
    methods.at(method_name)();
  }
  cin.ignore();
  out_stream.seekp(-1, ios_base::end); out_stream << ']';
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
