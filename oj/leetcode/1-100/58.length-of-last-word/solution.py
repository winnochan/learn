class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        b = None
        e = None
        for i in range(len(s) - 1, -1, -1):
            if e is None:
                if s[i] != ' ':
                    e = i
            elif b is None:
                if s[i] == ' ':
                    b = i
            else:
                break
        if e is None:
            e = -1
        if b is None:
            b = -1
        # print(b, e)
        return e - b
