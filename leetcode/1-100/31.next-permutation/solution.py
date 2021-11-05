class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] < nums[i+1]:
                for j in range(len(nums) - 1, i, -1):
                    if nums[j] > nums[i]:
                        nums[j], nums[i] = nums[i], nums[j]
                        for k in range(i + 1, len(nums)):
                            l, r = k, len(nums) - k + i
                            if l >= r:
                                break
                            nums[l], nums[r] = nums[r], nums[l]
                        return
        return nums.reverse()
