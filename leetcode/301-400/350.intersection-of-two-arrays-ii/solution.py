class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        doc = {}
        for n in nums1:
            if n not in doc:
                doc[n] = 1
            else:
                doc[n] += 1
        result = []
        for n in nums2:
            if not doc:
                break
            if n not in doc:
                continue
            doc[n] -= 1
            result.append(n)
            if not doc[n]:
                del doc[n]
        return result
