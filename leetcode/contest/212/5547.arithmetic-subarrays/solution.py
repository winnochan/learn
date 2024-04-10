class Solution:
    def checkArithmeticSubarrays(
        self, nums: List[int], l: List[int], r: List[int]
    ) -> List[bool]:
        result = []
        for i in range(len(l)):
            low = l[i]
            high = r[i]
            sortedNums = sorted(nums[low : high + 1])
            diff = sortedNums[1] - sortedNums[0]
            ret = True
            for j in range(1, len(sortedNums) - 1):
                if sortedNums[j + 1] - sortedNums[j] != diff:
                    ret = False
                    break
            result.append(ret)
        return result
