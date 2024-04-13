class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not len(strs):
            return ""
        if len(strs) == 1:
            return strs[0]
        arr = []
        i = 0
        while True:
            if i >= len(strs[0]):
                break
            c = strs[0][i]
            for j in range(1, len(strs)):
                if i >= len(strs[j]) or strs[j][i] != c:
                    return "".join(arr)
            arr.append(c)
            i += 1
        return "".join(arr)
