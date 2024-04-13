class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        doc = {}
        for c in s:
            if c not in doc:
                doc[c] = 1
            else:
                doc[c] += 1
        for c in t:
            if c not in doc:
                return False
            doc[c] -= 1
            if not doc[c]:
                del doc[c]
        return not doc
