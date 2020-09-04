class Solution(object):
    def mySqrt(self, x):
        low = 1
        high = x
        while low <= high:
            mid = (low+high)//2
            sq = mid*mid
            if sq == x:
                return mid
            elif sq > x:
                high = mid-1
            else:
                low = mid+1
        return low-1
            
        
        
        
