class Solution:
    def maxArea(self, height: List[int]) -> int:
        j = 0
        k = len(height) - 1
        area = 0
        while j < k:
            temp = min(height[j], height[k]) * (k - j)
            if temp > area:
                area = temp
            if height[j] < height[k]:
                j += 1
            else:
                k -= 1
        return area
