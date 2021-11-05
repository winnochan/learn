class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        ret = []
        pre = 0
        cur = 1
        while cur < len(s):
            if s[cur] != s[pre]:
                if cur - pre >= 3:
                    ret.append([pre, cur - 1])
                pre = cur
            cur += 1
        if cur - pre >= 3:
            ret.append([pre, cur - 1])
        return ret
