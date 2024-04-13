class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        l = len(nums)
        ret = [0] * l
        doc = {}
        for i in range(l):
            if nums[i] not in doc:
                doc[nums[i]] = [i]
            else:
                doc[nums[i]].append(i)
        # print(doc)
        nums.sort()
        i = 1
        while i < len(nums):
            if nums[i] > nums[i - 1]:
                ids = doc[nums[i]]
                for index in ids:
                    ret[index] = i
            i += 1
        return ret
