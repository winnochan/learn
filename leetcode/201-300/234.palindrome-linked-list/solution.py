# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        if not head.next.next:
            return head.val == head.next.val
        oneStep = head
        twoStep = head
        while True:
            oneStep = oneStep.next
            twoStep = twoStep.next.next
            if not twoStep or not twoStep.next or not twoStep.next.next:
                break
        # print(oneStep, twoStep)
        nextStep = oneStep.next
        if not twoStep.next:
            # 单数
            oneStep.next = None
            while nextStep:
                temp = nextStep
                nextStep = nextStep.next
                temp.next = oneStep
                oneStep = temp
            # print(head, oneStep)
            while oneStep != head:
                if head.val != oneStep.val:
                    return False
                head = head.next
                oneStep = oneStep.next
        else:
            # 双数
            oneStep.next = None
            first = True
            while nextStep:
                temp = nextStep
                nextStep = nextStep.next
                temp.next = oneStep if not first else None
                oneStep = temp
                first = False
            # print(head, oneStep)
            while oneStep != head:
                if head.val != oneStep.val:
                    return False
                head = head.next
                oneStep = oneStep.next
        return True

        # if not head or not head.next:
        #     return True
        # arr = []
        # while head:
        #     arr.append(head.val)
        #     head = head.next
        # print(arr)
        # al = len(arr)
        # for i in range(al // 2):
        #     if arr[i] != arr[al - i - 1]:
        #         return False
        # return True
