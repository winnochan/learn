import sys


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        return self.greedy(gas, cost)

    def greedy(self, gas: List[int], cost: List[int]) -> int:
        s = 0
        ms = sys.maxsize
        mi = 0
        n = len(gas)
        for i in range(n):
            s += gas[i] - cost[i]
            if s < ms:
                ms = s
                mi = i
        return (mi + 1) % n if s >= 0 else -1

    def bf(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        for j in range(n):
            suc = True
            cur = 0
            for k in range(n):
                i = (j + k) % n
                cur += gas[i] - cost[i]
                if cur < 0:
                    suc = False
                    break
            if suc:
                return j
        return -1
