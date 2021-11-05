class Solution:
    def longestMountain(self, A: List[int]) -> int:
        if len(A) < 3:
            return 0
        positive = 0
        negative = 0
        mountain = 0
        for i in range(1, len(A)):
            sig = A[i] - A[i - 1]
            # 相等
            if sig == 0:
                # 当正数和负数都大于0的话, 则出现过山脉形状, 结算一次
                if positive > 0 and negative > 0 and positive + negative > mountain:
                    mountain = positive + negative
                positive = 0
                negative = 0
            # 递增
            elif sig > 0:
                # 当正数和负数都大于0的话, 则出现过山脉形状, 结算一次
                if positive > 0 and negative > 0:
                    if positive + negative > mountain:
                        mountain = positive + negative
                    positive = 2
                # 递增正数
                else:
                    positive = positive + 1 if positive else 2
                negative = 0
            # 递减
            else:
                negative += 1
        if positive > 0 and negative > 0 and positive + negative > mountain:
            mountain = positive + negative

        return mountain
