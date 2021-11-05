# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head
        doc = set([head.val])
        node = head
        while node.next:
            if node.next.val in doc:
                node.next = node.next.next
            else:
                doc.add(node.next.val)
                node = node.next
        return head
