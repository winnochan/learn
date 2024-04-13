# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = node = None
        while l1 and l2:
            if l1.val < l2.val:
                if not head:
                    head = node = l1
                else:
                    node.next = l1
                    node = node.next
                l1 = l1.next
            else:
                if not head:
                    head = node = l2
                else:
                    node.next = l2
                    node = node.next
                l2 = l2.next
        if l1:
            if not node:
                return l1
            node.next = l1
        if l2:
            if not node:
                return l2
            node.next = l2
        return head
