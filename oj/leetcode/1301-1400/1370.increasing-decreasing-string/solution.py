class Solution:
    def sortString(self, s: str) -> str:
        ret = []
        doc = {}
        for c in s:
            if c not in doc:
                doc[c] = 1
            else:
                doc[c] += 1
        arr = sorted(doc.keys())
        rev = list(reversed(arr))
        while len(ret) < len(s):
            for c in arr:
                if doc[c]:
                    ret.append(c)
                    doc[c] -= 1
            for c in rev:
                if doc[c]:
                    ret.append(c)
                    doc[c] -= 1
        return ''.join(ret)
