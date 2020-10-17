class Solution:
    def isHappy(self, n: int) -> bool:
        if n <= 0:
            return False
        if n == 1:
            return True
        count = 0
        while count < 10:
            total = 0
            for digit in str(n):
                total += int(digit)**2
            if total == 1:
                return True
            n = total
            count+=1
        return False
                
            
                
        
        
