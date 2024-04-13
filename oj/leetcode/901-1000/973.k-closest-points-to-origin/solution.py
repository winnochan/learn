class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        arr = [(points[i][0]**2 + points[i][1] ** 2, points[i]) for i in range(len(points))]
        heapq.heapify(arr)
        ret = heapq.nsmallest(K, arr)
        return [ret[i][1] for i in range(len(ret))]
