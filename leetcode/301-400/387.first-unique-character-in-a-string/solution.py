class Solution:
    def firstUniqChar(self, s: str) -> int:
        base = ord('a')
        count = 26 * [0]
        for c in s:
            offset = ord(c) - base
            if count[offset] > 1:
                continue
            count[offset] += 1
        for i in range(len(s)):
            offset = ord(s[i]) - base
            if count[offset] > 1:
                continue
            return i
        return -1
