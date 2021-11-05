class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        doc = {}
        for n in arr:
            if n not in doc:
                doc[n] = 1
            else:
                doc[n] += 1
        cnt = {}
        for n in doc:
            if doc[n] not in cnt:
                cnt[doc[n]] = n
            else:
                return False
        return True
