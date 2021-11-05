class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        r = self.getRate(coordinates[0], coordinates[1])
        for i in range(2, len(coordinates)):
            if self.getRate(coordinates[0], coordinates[i]) != r:
                return False
        return True

    def getRate(self, p1: List[int], p2: List[int]) -> float:
        if p1[0] == p2[0]:
            return float('inf')
        return (p1[1] - p2[1]) / (p1[0] - p2[0])
