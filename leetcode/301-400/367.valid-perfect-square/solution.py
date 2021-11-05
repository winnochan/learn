class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l, r = 1, num
        while l <= r:
            m = (l + r) // 2
            n = m ** 2
            if n == num:
                return True
            if n > num:
                r = m - 1
            else:
                l = m + 1
        return False
