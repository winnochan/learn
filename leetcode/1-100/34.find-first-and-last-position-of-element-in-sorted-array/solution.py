import bisect

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        left = bisect.bisect_left(nums, target)
        if left == len(nums) or nums[left] != target:
            return [-1, -1]
        return [left, bisect.bisect_right(nums, target) - 1]
