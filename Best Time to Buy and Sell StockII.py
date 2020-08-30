class Solution(object):
    def maxProfit(self, prices):
        moreTrans = i = 0
        while i < len(prices)-1:
            if prices[i] < prices[i+1]:
                moreTrans+=prices[i+1]-prices[i]
            i+=1
        return moreTrans
            
            
        
       
        
