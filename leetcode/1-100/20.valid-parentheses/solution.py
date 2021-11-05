class Solution:
    def isValid(self, s: str) -> bool:
        arr = []
        for c in s:
            if c == '(' or c == '{' or c == '[':
                arr.append(c)
                continue
            elif c == ')':
                if not arr or arr[-1] != '(':
                    return False
                arr.pop()
            elif c == ']':
                if not arr or arr[-1] != '[':
                    return False
                arr.pop()
            elif c == '}':
                if not arr or arr[-1] != '{':
                    return False
                arr.pop()
            else:
                return False
        return not arr
