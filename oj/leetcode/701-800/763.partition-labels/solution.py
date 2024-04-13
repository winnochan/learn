class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        chars = 26 * [None]
        slen = len(S)
        anum = ord("a")
        for i in range(slen):
            chars[ord(S[i]) - anum] = i

        result = []
        i = 0
        while i < slen:
            j = i + 1
            k = chars[ord(S[i]) - anum]
            while j < k:
                if chars[ord(S[j]) - anum] > k:
                    k = chars[ord(S[j]) - anum]
                j += 1
            result.append(k - i + 1)
            i = k + 1
        return result
