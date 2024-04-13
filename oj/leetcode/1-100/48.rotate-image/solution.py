class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        temp = None

        for x in range(N // 2):
            for y in range(x, N - x - 1):
                tx = x
                ty = y
                for j in range(3):
                    rx = ty
                    ry = N - tx - 1
                    # print(tx, ty, rx, ry)
                    temp = matrix[rx][ry]
                    matrix[rx][ry] = matrix[x][y]
                    matrix[x][y] = temp
                    tx = rx
                    ty = ry
