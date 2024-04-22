// Created by WinnoChan at 2024/04/22 15:11
// leetgo: 1.4.5
// https://leetcode.cn/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* node = head;
        for (int i = 1; i < left; i++) {
            prev = node;
            node = node->next;
        }
        ListNode* leftPartTail = prev;
        ListNode* midPartTail = node;

        prev = nullptr;
        ListNode* next = nullptr;
        for (int i = left; i <= right; i++) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        midPartTail->next = node;

        if (leftPartTail) {
            leftPartTail->next = prev;
        } else {
            head = prev;
        }

        return head;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  ListNode* head;
  LeetCodeIO::scan(cin, head);
  int left;
  LeetCodeIO::scan(cin, left);
  int right;
  LeetCodeIO::scan(cin, right);

  Solution *obj = new Solution();
  auto res = obj->reverseBetween(head, left, right);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
