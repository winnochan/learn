class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        result = len(A) * [0]
        j, k = 0, 1
        for i in range(len(A)):
            if A[i] % 2 == 0:
                result[j] = A[i]
                j += 2
            else:
                result[k] = A[i]
                k += 2
        return result
