from typing import List
from pprint import pprint


class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows = len(heights)
        cols = len(heights[0])
        path = [cols * [10 ** 7] for _ in range(rows)]
        path[0][0] = 0
        self.dfs(heights, path)

        return path[rows - 1][cols - 1]

    def dfs(self, heights: List[List[int]], path: List[List[int]], j=0, k=0) -> None:
        r = len(heights)
        c = len(heights[0])
        if 0 <= j < r and 0 <= k - 1 < c:
            # go left
            dis = max(path[j][k], abs(heights[j][k] - heights[j][k - 1]))
            old = path[j][k - 1]
            if dis < old:
                path[j][k - 1] = dis
                # print("go left")
                # pprint(path)
                self.dfs(heights, path, j, k - 1)
        if 0 <= j - 1 < r and 0 <= k < c:
            # go up
            dis = max(path[j][k], abs(heights[j - 1][k] - heights[j][k]))
            old = path[j - 1][k]
            if dis < old:
                path[j - 1][k] = dis
                # print("go up")
                # pprint(path)
                self.dfs(heights, path, j - 1, k)
        if 0 <= j < r and 0 <= k + 1 < c:
            # go right
            dis = max(path[j][k], abs(heights[j][k] - heights[j][k + 1]))
            old = path[j][k + 1]
            if dis < old:
                path[j][k + 1] = dis
                # print("go right")
                # pprint(path)
                self.dfs(heights, path, j, k + 1)
        if 0 <= j + 1 < r and 0 <= k < c:
            # go down
            dis = max(path[j][k], abs(heights[j + 1][k] - heights[j][k]))
            old = path[j + 1][k]
            if dis < old:
                path[j + 1][k] = dis
                # print("go down")
                # pprint(path)
                self.dfs(heights, path, j + 1, k)

        return


s = Solution()
print(s.minimumEffortPath([[1, 2, 2], [3, 8, 2], [5, 3, 5]]))
print(s.minimumEffortPath([[1, 2, 3], [3, 8, 4], [5, 3, 5]]))
print(s.minimumEffortPath([[1, 10, 6, 7, 9, 10, 4, 9]]))
