class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        if not nums:
            return 0
        sums = [nums[0]]
        for i in range(1, len(nums)):
            sums.append(sums[-1] + nums[i])
        dp = [(sums[i], i) for i in range(len(sums))]
        dp.sort()
        # print(dp)
        count = 0
        for i in range(len(dp)):
            num = dp[i][0]
            l = self.search(dp, lower + num - 0.5)
            r = self.search(dp, upper + num + 0.5)
            # print(i, l, r)
            if lower <= num <= upper:
                count += 1
            for j in range(l, r):
                if dp[i][1] < dp[j][1] and lower <= dp[j][0] - dp[i][0] <= upper:
                    count += 1
            # print(i, count)
        return count

    def search(self, dp: List[tuple], num: float) -> int:
        l, r = 0, len(dp) - 1
        while l <= r:
            m = (l + r) // 2
            if dp[m][0] == num:
                return m
            if dp[m][0] > num:
                r = m - 1
            else:
                l = m + 1
        return l
