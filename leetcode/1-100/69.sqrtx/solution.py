class Solution:
    def mySqrt(self, x: int) -> int:
        l = 0
        r = x
        while l <= r:
            m = (l + r) // 2
            if m ** 2 == x:
                return m
            if x > m ** 2:
                l = m + 1
            else:
                r = m - 1
        return l - 1
