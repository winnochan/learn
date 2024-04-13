class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        isIn = False
        inPrice = 100000

        result = 0
        for i in range(len(prices) - 1):
            if prices[i] < prices[i + 1] and not isIn:
                isIn = True
                inPrice = prices[i]
                # print(inPrice)
            elif prices[i] > prices[i + 1] and isIn and prices[i] > inPrice:
                result += prices[i] - inPrice
                isIn = False
                # print(inPrice, prices[i], result)
        if isIn and prices[-1] > inPrice:
            result += prices[-1] - inPrice
        return result
