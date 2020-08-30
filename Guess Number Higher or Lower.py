class Solution(object):
    def guessNumber(self, n):
        low = 0
        high = n
        while low <= high:
            mid = (low+high)//2
            val = guess(mid)
            if val == 0:
                return mid
            elif val == -1:
                high = mid-1
            else:
                low = mid+1
        
