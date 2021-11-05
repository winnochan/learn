class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        j = 0
        k = 0
        while True:
            c = None
            cnum = 0
            while j < len(name):
                c = name[j]
                cnum += 1
                if j == len(name) - 1 or c != name[j + 1]:
                    j += 1
                    break
                j += 1
            # print(c, cnum)

            while k < len(typed):
                if typed[k] != c:
                    return False
                cnum -= 1
                if k == len(typed) - 1 or typed[k] != typed[k + 1]:
                    k += 1
                    break
                k += 1
            # print(c, cnum)

            if cnum > 0:
                return False

            if not c:
                break
        return True
