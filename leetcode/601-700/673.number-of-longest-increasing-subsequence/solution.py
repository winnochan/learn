class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        l = len(nums)
        dp = l * [1]
        count = l * [1]
        m = 1
        for j in range(1, l):
            for k in range(j):
                if nums[j] > nums[k]:
                    if dp[k] + 1 > dp[j]:
                        dp[j] = dp[k] + 1
                        count[j] = count[k]
                        if dp[j] > m:
                            m = dp[j]
                    elif dp[k] + 1 == dp[j]:
                        # print(k, j, nums[k], nums[j], dp[k], dp[j])
                        count[j] += count[k]

        # print(dp)
        # print(count)
        ret = 0
        for i in range(l):
            if dp[i] == m:
                ret += count[i]
        return ret
