class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if not nums:
            return False
        l = len(nums)

        i = 0
        m = nums[0]
        while i <= m:
            n = i + nums[i]
            if n >= l - 1:
                return True
            if n > m:
                m = n
            i += 1

        return False
