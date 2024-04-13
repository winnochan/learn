class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        last = nums[r]
        while l < r:
            m = (l + r) // 2
            if nums[m] > last:
                l = m + 1
            else:
                r = m
        return nums[l]
