class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sortedStrs = [''.join(sorted(list(s))) for s in strs]
        index = 0
        doc = {}
        for i in range(len(sortedStrs)):
            if sortedStrs[i] not in doc:
                doc[sortedStrs[i]] = [i]
            else:
                doc[sortedStrs[i]].append(i)
        ret = []
        for arr in doc.values():
            ret.append([strs[i] for i in arr])
        return ret
