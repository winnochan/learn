class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = []
        for n in range(numRows):
            if not ret:
                ret.append([1])
                continue
            row = (n + 1) * [0]
            for i in range(n + 1):
                if i - 1 >= 0 and i < len(ret[-1]):
                    row[i] = ret[-1][i - 1] + ret[-1][i]
                else:
                    row[i] = 1
            ret.append(row)
        return ret
