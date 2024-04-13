class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        lastStr = "1"
        for i in range(n - 1):
            count = 1
            curStr = []
            for j in range(len(lastStr)):
                if j + 1 < len(lastStr) and lastStr[j] == lastStr[j + 1]:
                    count += 1
                else:
                    curStr.append(str(count) + lastStr[j])
                    count = 1
            lastStr = "".join(curStr)
        return lastStr


# s = Solution()
# arr = []
# for i in range(1, 31):
#     arr.append(s.countAndSay(i))
# print(arr)
