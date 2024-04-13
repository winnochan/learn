class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A.sort(key=lambda x: -x)
        for i in range(len(A) - 2):
            if A[i] >= A[i+1] + A[i+2]:
                continue
            return A[i] + A[i+1] + A[i+2]
        return 0
