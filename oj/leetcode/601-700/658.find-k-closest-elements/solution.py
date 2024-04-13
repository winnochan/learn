class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l = 0
        r = len(arr) - 1
        i = 0
        while l < r:
            m = (l + r) // 2
            if arr[m] == x:
                i = m
                break
            if arr[m] > x:
                r = m
            else:
                l = m + 1
        if arr[l] > x:
            if l - 1 >= 0 and abs(arr[l - 1] - x) <= abs(arr[l] - x):
                i = l - 1
            else:
                i = l
        else:
            if l + 1 < len(arr) and abs(arr[l + 1] - x) < abs(arr[l] - x):
                i = l + 1
            else:
                i = l
        k -= 1
        l = i
        r = i
        while k > 0:
            if r + 1 >= len(arr):
                l -= 1
            elif l - 1 < 0:
                r += 1
            elif abs(arr[l - 1] - x) <= abs(arr[r + 1] - x):
                l -= 1
            else:
                r += 1
            k -= 1
        return arr[l : r + 1]
