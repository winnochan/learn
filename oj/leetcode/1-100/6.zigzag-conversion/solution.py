class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1:
            return s
        arr = [[] for _ in range(numRows)]
        offset = -1
        r = 0
        for i in range(len(s)):
            if i % (numRows - 1) == 0:
                offset = -offset
            # print(r, offset)
            arr[r].append(s[i])
            r += offset

        return "".join(["".join(arr[i]) for i in range(numRows)])
