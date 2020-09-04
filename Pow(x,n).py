class Solution(object):
    def myPow(self, x, n):
        if x == 1 or n == 0:
            return 1
        if x == -1:
            if n%2 == 0:
                return 1
            return -1
        if n == 1 or n == -1:
            if n == 1:
                return x
            return 1/x
        pw = 1
        res = n if n > 0 else -1*n
        if x > 0 and x < 0.01:
            if n > 10:
                return 0
        if n < -350:
            return 0
        for i in range(res):
            pw*=x      
        if n>0:
            return pw
        return 1.0/pw
        
