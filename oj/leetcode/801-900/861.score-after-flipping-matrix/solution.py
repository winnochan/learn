class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        for i in range(len(A)):
            if not A[i][0]:
                self.reverseRow(A, i)
        for i in range(len(A[0])):
            if not self.isOneMore(A, i):
                self.reverseCol(A, i)
        ret = 0
        for i in range(len(A)):
            ret += self.getValue(A, i)
        return ret

    def getValue(self, A: List[List[int]], row: int) -> int:
        exp = 1
        ret = 0
        for i in range(len(A[row]) - 1, -1, -1):
            ret += A[row][i] * exp
            exp *= 2
        return ret

    def isOneMore(self, A: List[List[int]], col: int) -> bool:
        rows = len(A)
        num0 = 0
        for i in range(rows):
            if not A[i][col]:
                num0 += 1
        return rows - num0 > num0

    def reverseRow(self, A: List[List[int]], row: int) -> None:
        arr = A[row]
        for i in range(len(arr)):
            arr[i] = 0 if arr[i] else 1
        return

    def reverseCol(self, A: List[List[int]], col: int) -> None:
        for i in range(len(A)):
            A[i][col] = 0 if A[i][col] else 1
        return
