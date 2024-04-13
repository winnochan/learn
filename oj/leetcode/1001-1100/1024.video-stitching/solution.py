from typing import List


class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        dp = (T + 1) * [101]
        dp[0] = 0
        for i in range(1, T + 1):
            for [l, h] in clips:
                if l < i <= h:
                    dp[i] = min(dp[i], dp[l] + 1)
        return dp[T] if dp[T] <= 100 else -1
