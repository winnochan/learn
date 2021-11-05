# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        while head:
            if head.val == val:
                temp = head.next
                head.next = None
                head = temp
            else:
                break

        if not head:
            return head
        if not head.next:
            if head.val == val:
                return None
            return head

        # print(head)

        pre = head
        cur = head.next
        while cur:
            if cur.val == val:
                temp = cur.next
                cur.next = None
                pre.next = temp
                cur = temp
                continue
            pre = pre.next
            if pre:
                cur = pre.next
            else:
                break
        return head
