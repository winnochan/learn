class Solution:
    def fib(self, n: int, c={0: 0, 1: 1, 2: 1}) -> int:
        # if n in c, then return c[n]
        if n in c:
            return c[n]

        # let i = n // 2
        i = n // 2
        f = self.fib(i + 1, c) * self.fib(n - i, c) + self.fib(i, c) * self.fib(n - i - 1, c)
        c[n] = f

        # test print size of c
        # print('calculate fibonacci for %d and size of c is %d' % (n, len(c)))

        return f
