class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        return self.n2(A, B, C, D)

    def n2(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        doc1 = self.mergeDict(A, B)
        ret = 0
        for j in range(len(C)):
            for k in range(len(D)):
                num = -C[j] - D[k]
                if num in doc1:
                    ret += doc1[num]
        return ret

    def mergeDict(self, A: List[int], B: List[int]) -> Dict[int, int]:
        al = len(A)
        bl = len(B)
        doc = {}
        for j in range(al):
            for k in range(bl):
                s = A[j] + B[k]
                if s not in doc:
                    doc[s] = 1
                else:
                    doc[s] += 1
        return doc

    def n2logn(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        arr1 = self.mergeList(A, B)
        arr2 = self.mergeList(C, D)
        arr1.sort()
        arr2.sort()
        ret = 0
        for n in arr1:
            ret += bisect.bisect_right(arr2, -n) - bisect.bisect_left(arr2, -n)
        # print(arr1, arr2)
        # print(bisect.bisect_left(arr1, 0), bisect.bisect_right(arr1, 0))
        return ret

    def mergeList(self, A: List[int], B: List[int]) -> List[int]:
        al = len(A)
        bl = len(B)
        arr = [0] * (al * bl)
        for j in range(al):
            for k in range(bl):
                arr[j*bl+k] = A[j] + B[k]
        return arr
