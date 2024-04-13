# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next or not head.next.next:
            return head
        odd = head
        even = head.next
        evenHead = even
        while even.next:
            odd.next = even.next
            even.next = even.next.next

            odd = odd.next
            even = even.next
            if not even:
                break
        odd.next = evenHead
        return head
