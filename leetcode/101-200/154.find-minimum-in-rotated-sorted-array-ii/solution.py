class Solution:
    def findMin(self, nums: List[int]) -> int:
        s = len(nums)
        if s <= 2:
            return min(nums)
        l, r = 0, s - 1
        if nums[l] == nums[r]:
            while l + 1 < s and nums[l] == nums[l + 1]:
                l += 1
            if l == s - 1:
                return nums[0]
            while r - 1 >= 0 and nums[r] == nums[r - 1]:
                r -= 1
            if r == 0:
                return nums[0]
        if nums[l] == nums[r]:
            l += 1
        t = nums[r]
        while l < r:
            m = (l + r) // 2
            if nums[m] <= t:
                r = m
            else:
                l = m + 1
        return nums[l]
