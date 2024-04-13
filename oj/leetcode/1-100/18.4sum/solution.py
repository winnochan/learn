class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        doc = {}
        result = []
        for a in range(len(nums) - 3):
            for b in range(a + 2, len(nums) - 1):
                c = b - 1
                d = b + 1
                while c > a and d < len(nums):
                    total = nums[a] + nums[b] + nums[c] + nums[d]
                    if total == target:
                        key = tuple([nums[a], nums[c], nums[b], nums[d]])
                        if key in doc:
                            c -= 1
                            d += 1
                            continue
                        doc[key] = 1
                        result.append([nums[a], nums[c], nums[b], nums[d]])
                        c -= 1
                        d += 1
                    elif total > target:
                        c -= 1
                    else:
                        d += 1

        return result
