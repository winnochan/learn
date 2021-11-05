class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        l = len(nums)
        ret = None
        # print(nums)
        for i in range(len(nums) - 2):
            if ret == target:
                return target
            j, k = i + 1, l - 1
            if ret is None or abs(nums[i] + nums[j] + nums[k] - target) < abs(ret - target):
                ret = nums[i] + nums[j] + nums[k]
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                # print(nums[i], nums[j], nums[k], s, ret, target)
                if abs(s - target) < abs(ret - target):
                    ret = s
                if ret == target:
                    return target
                elif s > target:
                    k -= 1
                else:
                    j += 1
        return ret
