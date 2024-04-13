class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if not nums:
            return -1
        if len(nums) == 1:
            return 0
        if len(nums) == 2:
            return 0 if nums[0] > nums[1] else 1
        l = 0
        r = len(nums) - 1
        while l < r:
            m = (l + r) // 2
            if (
                m - 1 >= l
                and m + 1 <= r
                and nums[m] > nums[m - 1]
                and nums[m] > nums[m + 1]
            ):
                return m
            if m - 1 >= l:
                if nums[m - 1] > nums[m]:
                    r = m - 1
                else:
                    l = m + 1
            if m + 1 <= r:
                if nums[m + 1] > nums[m]:
                    l = m + 1
                else:
                    r = m - 1
        return l
