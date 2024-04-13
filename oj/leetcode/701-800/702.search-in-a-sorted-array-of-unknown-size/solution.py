# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader:
#    def get(self, index: int) -> int:


class Solution:
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        INVALID = 2147483647
        if target == INVALID:
            return -1
        l, r = 0, 1
        low = reader.get(0)
        if target < low:
            return -1
        while True:
            if low <= target <= reader.get(r):
                break
            r *= 2
        while l <= r:
            m = (l + r) // 2
            n = reader.get(m)
            if n == target:
                return m
            if n > target:
                r = m - 1
            else:
                l = m + 1
        return -1
