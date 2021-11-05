# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        prev = head
        curr = head.next
        if curr.val < prev.val:
            curr.val, prev.val = prev.val, curr.val
        prev = curr
        curr = curr.next
        while curr:
            # print(prev.val, curr.val)
            if curr.val <= head.val:
                prev.next = curr.next
                curr.next = head
                head = curr
                curr = prev.next
                continue
            if curr.val < prev.val:
                temp = head
                while temp != prev:
                    if temp.val <= curr.val <= temp.next.val:
                        prev.next = curr.next
                        curr.next = temp.next
                        temp.next = curr
                        curr = prev.next
                        break
                    temp = temp.next
            else:
                prev = curr
                curr = prev.next
        return head
