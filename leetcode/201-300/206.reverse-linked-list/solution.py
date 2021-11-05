# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head

        stack = []
        while head:
            stack.append(head)
            head = head.next

        node = stack.pop()
        head = node
        while stack:
            node.next = stack.pop()
            node = node.next
        node.next = None
        return head
