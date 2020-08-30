class Solution(object):
    def maxProfit(self, prices):
        maxProfit = 0
        if prices:
            minPrice = prices[0]
        for i in prices:
            if i < minPrice:
                minPrice = i
            else:
                if i-minPrice > maxProfit:
                    maxProfit = i-minPrice
        return maxProfit

