class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        c = 0
        for row in range(rows):
            for col in range(cols):
                if not grid[row][col]:
                    continue
                if row == 0:
                    c += 1
                    if row < rows - 1 and grid[row + 1][col] == 0:
                        c += 1
                if row == rows - 1:
                    c += 1
                    if row > 0 and grid[row - 1][col] == 0:
                        c += 1
                if col == 0:
                    c += 1
                    if col < cols - 1 and grid[row][col + 1] == 0:
                        c += 1
                if col == cols - 1:
                    c += 1
                    if col > 0 and grid[row][col - 1] == 0:
                        c += 1
                if 0 < row < rows - 1:
                    if grid[row - 1][col] == 0:
                        c += 1
                    if grid[row + 1][col] == 0:
                        c += 1
                if 0 < col < cols - 1:
                    if grid[row][col - 1] == 0:
                        c += 1
                    if grid[row][col + 1] == 0:
                        c += 1
        return c
