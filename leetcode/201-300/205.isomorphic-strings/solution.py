class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        slen = len(s)
        tlen = len(t)
        if slen != tlen:
            return False

        sdoc = {}
        tdoc = {}
        for i in range(slen):
            if s[i] not in sdoc and t[i] not in tdoc:
                sdoc[s[i]] = t[i]
                tdoc[t[i]] = s[i]
            elif s[i] in sdoc and t[i] in tdoc:
                if sdoc[s[i]] != t[i] or tdoc[t[i]] != s[i]:
                    return False
            else:
                return False
        return True
