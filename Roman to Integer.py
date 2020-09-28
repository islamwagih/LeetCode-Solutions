class Solution(object):
    def romanToInt(self, s):
        simpols = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        value = 0
        last = float('inf')            
        for curr in s:
            currVal = simpols[curr]
            if last < currVal:
                value -= 2*last     
            value += currVal
            last = currVal
        return value
            
                
        
       
            

        
        
