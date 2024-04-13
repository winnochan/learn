class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort(key=lambda p: p[1])
        c = 1
        upper = points[0][1]
        for p in points:
            if p[0] > upper:
                upper = p[1]
                c += 1
        return c
