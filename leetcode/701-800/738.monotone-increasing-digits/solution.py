class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        arr1 = []
        arr2 = []
        while N:
            arr1.append(N % 10)
            N //= 10
        idx = -1
        while arr1:
            if not arr2 or arr1[-1] >= arr2[-1]:
                arr2.append(arr1.pop())
            else:
                idx = len(arr2) - 1
                while idx > 0:
                    if arr2[idx] == arr2[idx - 1]:
                        idx -= 1
                        arr1.append(arr2.pop())
                    else:
                        break
                arr2.extend(len(arr1) * [9])
                break
        # print(arr1)
        ret = 0
        exp = 0
        for i in range(len(arr2) - 1, -1, -1):
            ret += arr2[i] * (10 ** exp)
            if idx == i:
                ret -= 10 ** exp
            exp += 1
        return ret
