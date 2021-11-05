class Solution:
    def maxEnvelopes(self, e: List[List[int]]) -> int:
        return self.dp_n2(e)

    def dp_n2(self, e: List[List[int]]) -> int:
        if not e:
            return 0
        e.sort(key=lambda x: (x[0], -x[1]))
        n = len(e)
        dp = [1] * n
        for k in range(1, n):
            for j in range(k):
                if e[k][0] > e[j][0] and e[k][1] > e[j][1] and dp[j] + 1 > dp[k]:
                    dp[k] = dp[j] + 1
        return max(dp)
