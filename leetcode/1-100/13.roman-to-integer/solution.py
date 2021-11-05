class Solution:
    def romanToInt(self, s: str) -> int:
        half = {"V": 5, "L": 50, "D": 500}
        result = 0
        i = 0
        sl = len(s)
        while i < sl:
            if s[i] in half:
                result += half[s[i]]
                i += 1
            elif s[i] == "M":
                result += 1000
                i += 1
            elif s[i] == "C":
                if i + 1 < sl and s[i + 1] == "M":
                    i += 2
                    result += 900
                elif i + 1 < sl and s[i + 1] == "D":
                    i += 2
                    result += 400
                elif i + 2 < sl and s[i + 1] == "C" and s[i + 2] == "C":
                    i += 3
                    result += 300
                elif i + 1 < sl and s[i + 1] == "C":
                    i += 2
                    result += 200
                else:
                    i += 1
                    result += 100
            elif s[i] == "X":
                if i + 1 < sl and s[i + 1] == "C":
                    i += 2
                    result += 90
                elif i + 1 < sl and s[i + 1] == "L":
                    i += 2
                    result += 40
                elif i + 2 < sl and s[i + 1] == "X" and s[i + 2] == "X":
                    i += 3
                    result += 30
                elif i + 1 < sl and s[i + 1] == "X":
                    i += 2
                    result += 20
                else:
                    i += 1
                    result += 10
            elif s[i] == "I":
                if i + 1 < sl and s[i + 1] == "X":
                    i += 2
                    result += 9
                elif i + 1 < sl and s[i + 1] == "V":
                    i += 2
                    result += 4
                elif i + 2 < sl and s[i + 1] == "I" and s[i + 2] == "I":
                    i += 3
                    result += 3
                elif i + 1 < sl and s[i + 1] == "I":
                    i += 2
                    result += 2
                else:
                    i += 1
                    result += 1

        return result
