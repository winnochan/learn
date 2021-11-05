class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        parr = list(pattern)
        sarr = s.split(' ')
        if len(parr) != len(sarr):
            return False
        ati = {}
        doc = {}
        for i in range(len(parr)):
            k, v = parr[i], sarr[i]
            if k not in doc:
                doc[k] = v
                if v in ati:
                    return False
                ati[v] = k
            elif doc[k] != v:
                return False
        return True
