# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return head
        nodes = []
        temp = head
        while temp:
            nodes.append(temp)
            temp = temp.next
        l = len(nodes)
        for i in range((l + 1) // 2):
            if nodes[l - i - 1] == nodes[i]:
                nodes[i].next = None
                break
            if nodes[i].next == nodes[l - i - 1]:
                nodes[l - i - 1].next = None
                break
            nodes[l - i - 1].next = nodes[i].next
            nodes[i].next = nodes[l - i - 1]

        return head
