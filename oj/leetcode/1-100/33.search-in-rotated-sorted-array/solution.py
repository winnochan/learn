class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        last = nums[r]
        # 找到最小的数字下表
        while l <= r:
            m = (l + r) // 2
            if nums[m] > last:
                l = m + 1
            else:
                r = m - 1
        # 判断数字是在左半边还是右半边的数组
        if target > last:
            r = l - 1
            l = 0
        else:
            r = len(nums) - 1
        # 二分查找
        while l <= r:
            m = (l + r) // 2
            if nums[m] == target:
                return m
            elif nums[m] > target:
                r = m - 1
            else:
                l = m + 1
        return -1
