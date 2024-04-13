class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        A = A[::-1]
        c = 0
        for i in range(len(A)):
            if not K and not c:
                break
            A[i] += K % 10 + c
            c = A[i] // 10
            A[i] %= 10
            K //= 10
            # print(A, K, c)
        while K:
            n = K % 10 + c
            A.append(n % 10)
            c = n // 10
            K //= 10
        if c:
            A.append(c)
        return A[::-1]
