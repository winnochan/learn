class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        l = 0
        ret = []
        if not nums:
            return ret
        for i in range(len(nums) - 1):
            if nums[i] + 1 == nums[i + 1]:
                continue
            if i == l:
                ret.append(str(nums[i]))
            else:
                ret.append(str(nums[l]) + '->' + str(nums[i]))
            l = i + 1
        if len(nums) - 1 == l:
            ret.append(str(nums[-1]))
        else:
            ret.append(str(nums[l]) + '->' + str(nums[-1]))
        return ret
