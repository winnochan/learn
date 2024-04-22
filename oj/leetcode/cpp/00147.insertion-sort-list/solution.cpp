// Created by WinnoChan at 2024/04/23 05:28
// leetgo: 1.4.5
// https://leetcode.cn/problems/insertion-sort-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if (!head || !head->next) return head;

      ListNode* helper = new ListNode(0, head);
      ListNode* prev = head;
      ListNode* node = head->next;
      ListNode* temp;
      while (node) {
        // 特殊判断头部节点
        if (head->val > node->val) {
          // 此时, node应为新的头节点
          helper->next = node;
          node = node->next;
          prev->next = node;
          helper->next->next = head;
          head = helper->next;
        } else if (prev->val <= node->val) {
          // node应为新的尾节点
          prev = node;
          node = node->next;
        } else {
          // 找到应该插入的位置
          temp = head;
          while (temp != prev) {
            if (temp->val <= node->val && temp->next->val > node->val) {
              // 找到了
              node = node->next;
              prev->next->next = temp->next;
              temp->next = prev->next;
              prev->next = node;
              break;
            } else {
              // 没找到
              temp = temp->next;
            }
          }
        }
      }

      return helper->next;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode* head;
  LeetCodeIO::scan(cin, head);

  Solution *obj = new Solution();
  auto res = obj->insertionSortList(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
