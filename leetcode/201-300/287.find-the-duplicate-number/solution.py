class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.append(0)
        for i in range(len(nums)):
            if nums[i] == i:
                continue
            while nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                temp = nums[nums[i]]
                nums[nums[i]] = nums[i]
                nums[i] = temp
