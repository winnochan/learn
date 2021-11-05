class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        dp = n * [1]
        dp[0] = dp[1] = 0
        for i in range(2, n):
            for j in range(2, n):
                num = j * i
                if num >= n:
                    break
                if dp[num]:
                    dp[num] = 0
        return dp.count(1)
