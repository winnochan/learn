class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        return self.getResult(s, set(wordDict), 0)

    def getResult(self, s: str, strSet, begin: int, result=None):
        if result is None:
            result = []
        for end in range(begin + 1, len(s) + 1):
            subStr = s[begin:end]
            if subStr in strSet:
                result.append(subStr)
                self.getResult(s, strSet, end, result)
                if end == len(s):
                    pass
        return result
