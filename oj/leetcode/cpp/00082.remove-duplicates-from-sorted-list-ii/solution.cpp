// Created by WinnoChan at 2024/04/22 15:27
// leetgo: 1.4.5
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        int delVal = 1e8;
        ListNode* holder = new ListNode(delVal, head);

        ListNode* prev = holder;
        ListNode* node = head;
        while (node) {
            if (node->val == delVal) {
                prev->next = node->next;
                delete node;
                node = prev->next;
            } else if (node->next && node->val == node->next->val) {
                delVal = node->val;
            } else {
                prev = node;
                node = node->next;
            }
        }

        head = holder->next;
        delete holder;
        return head;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode* head;
  LeetCodeIO::scan(cin, head);

  Solution *obj = new Solution();
  auto res = obj->deleteDuplicates(head);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
