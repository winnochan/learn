class Solution:
    def jump(self, nums: List[int]) -> int:
        l = len(nums)
        if l <= 1:
            return 0
        i = 0
        c = 0
        m = 0
        while i <= m:
            temp = m
            for j in range(i, m + 1):
                t = j + nums[j]
                if t > temp:
                    temp = t
            if temp <= m:
                return 0
            c += 1
            if temp >= l - 1:
                return c
            i = m + 1
            m = temp

        return 0
