class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j, k = 0, 0
        ret = 0
        while j < len(g) and k < len(s):
            if s[k] >= g[j]:
                ret += 1
                j += 1
                k += 1
            else:
                k += 1
        return ret
