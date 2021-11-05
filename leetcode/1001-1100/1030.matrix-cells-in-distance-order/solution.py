class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        dis = [[] for _ in range(R + C)]
        for r in range(R):
            for c in range(C):
                dis[abs(r - r0) + abs(c - c0)].append([r, c])
        ret = []
        for d in dis:
            ret.extend(d)
        return ret
