class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0
        nums.sort()
        m = nums[1] - nums[0]
        for i in range(1, len(nums) - 1):
            n = nums[i+1] - nums[i]
            if n > m:
                m = n
        return m
