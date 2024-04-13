class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        ret = 0
        arr = []
        isIn = True
        pidx = 0
        for i in range(len(prices) - 1):
            if isIn:
                if prices[i] < prices[i + 1]:
                    pidx = i
                    isIn = False
            else:
                if prices[i] > prices[i + 1]:
                    arr.append((prices[pidx], prices[i]))
                    ret += prices[pidx] - prices[i]
                    isIn = True
        if not isIn and prices[-1] > prices[pidx]:
            arr.append((prices[pidx], prices[-1]))
            ret += prices[pidx] - prices[-1]
        print(ret)
        size = len(arr)
        mergeCost = size * [None]
        if size > k:
            # 需要合并
            for i in range(1, size):
                if arr[i][1] >= arr[i - 1][1] and arr[i][0] >= arr[i - 1][0]:
                    mergeCost[i] = (arr[i][0] - arr[i - 1][1], i)
        mergeCost = list(filter(lambda x: x is not None, mergeCost))
        mergeCost.sort()

        # ret = list()

        print(mergeCost)

        # if len(ret) <= k:
        #     return
