class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return float("inf")
        if n < 0:
            return 1 / self.myPow(x, -n)
        elif n == 0:
            return 1
        elif n % 2 == 0:
            ret = self.myPow(x, n // 2)
            return ret * ret
        else:
            ret = self.myPow(x, n // 2)
            return x * ret * ret
