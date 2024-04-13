import heapq
from typing import List


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        [min1, min2, min3] = heapq.nsmallest(3, nums)
        [max1, max2, max3] = heapq.nlargest(3, nums)
        return max(max1 * max2 * max3, min1 * min2 * min3, min1 * min2 * max1)
