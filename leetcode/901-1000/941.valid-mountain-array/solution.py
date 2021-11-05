class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        l = len(A)
        j, k = 0, l - 1
        while j + 1 < l and A[j] < A[j+1]:
            j += 1
        while k - 1 >= 0 and A[k - 1] > A[k]:
            k -= 1
        # print(j, k)
        return j != 0 and k != l - 1 and j == k
