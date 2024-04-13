class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        num = 0
        ret = []
        for n in A:
            num = num * 2 + n
            if not num % 5:
                ret.append(True)
            else:
                ret.append(False)
        return ret
