class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n, j, k = len(nums1), len(nums2), 0, 0
        a = m + n
        f = a // 2 - 1 if a % 2 == 0 else a // 2
        while j + k < f:
            if j == m:
                k += 1
            elif k == n:
                j += 1
            elif nums1[j] <= nums2[k]:
                j += 1
            else:
                k += 1
        if j == m:
            l = nums2[k]
            r = nums2[k + 1] if a % 2 == 0 else nums2[k]
        elif k == n:
            l = nums1[j]
            r = nums1[j + 1] if a % 2 == 0 else nums1[j]
        elif nums1[j] <= nums2[k]:
            l = nums1[j]
            r = min(nums1[j + 1], nums2[k]) if j + 1 < m else nums2[k]
        else:
            l = nums2[k]
            r = min(nums1[j], nums2[k + 1]) if k + 1 < n else nums1[j]
        return (l + r) / 2 if a % 2 == 0 else l / 1
