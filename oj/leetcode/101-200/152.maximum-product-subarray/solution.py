class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        minDp = nums[:]
        maxDp = nums[:]
        for i in range(1, len(nums)):
            if nums[i] == 0:
                continue
            minSum = minDp[i-1] * nums[i]
            maxSum = maxDp[i-1] * nums[i]
            if minSum < minDp[i] or maxSum < minDp[i]:
                minDp[i] = min(minSum, maxSum)
            if minSum > maxDp[i] or maxSum > maxDp[i]:
                maxDp[i] = max(minSum, maxSum)
        return max(maxDp)
