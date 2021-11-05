class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # return self.dp(nums)
        return self.greedy(nums)

    def dp(self, nums: List[int]) -> int:
        """
        O(n^2) solution.

        define dp[i] as length of longest increasing subsequence which ends with nums[i-1]
        """

        nlen = len(nums)
        maxl = 1 if nlen > 0 else 0
        dp = [1] * (nlen)

        for i in range(1, nlen):
            for j in range(i):
                if nums[i] > nums[j] and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    if dp[i] > maxl:
                        maxl = dp[i]

        return maxl

    def greedy(self, nums: List[int]) -> int:
        if not nums:
            return 0
        arr = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] > arr[-1]:
                arr.append(nums[i])
            else:
                s = self.search(arr, nums[i])
                if arr[s] > nums[i]:
                    arr[s] = nums[i]
        return len(arr)

    def search(self, nums: List[int], n: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            m = (l + r) // 2
            if nums[m] == n:
                return m
            if nums[m] < n:
                l = m + 1
            else:
                r = m
        return l
