class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        np = [tuple(sorted(p)) for p in dominoes]
        ret = 0
        doc = {}
        for p in np:
            if p not in doc:
                doc[p] = 1
            else:
                ret += doc[p]
                doc[p] += 1
        return ret
