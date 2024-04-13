class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l, r, n = 0, 0, len(nums)
        while l < n and r < n:
            if nums[l] != 0:
                l += 1
                continue
            if r < l:
                r = l
            if nums[r] == 0:
                r += 1
                continue
            self.swap(nums, l, r)

    def swap(self, nums, j, k):
        nums[j], nums[k] = nums[k], nums[j]
