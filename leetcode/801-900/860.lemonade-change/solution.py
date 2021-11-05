class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        doc = {
            5: 0,
            10: 0,
            20: 0,
        }
        for bill in bills:
            if bill == 5:
                doc[bill] += 1
            elif bill == 10:
                if not doc[5]:
                    return False
                doc[5] -= 1
                doc[10] += 1
            elif bill == 20:
                if doc[10] and doc[5]:
                    doc[5] -= 1
                    doc[10] -= 1
                    doc[20] += 1
                elif doc[5] >= 3:
                    doc[5] -= 3
                    doc[20] += 1
                else:
                    return False
        return True
