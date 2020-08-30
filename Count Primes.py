class Solution(object):
    def countPrimes(self, n):
        if n <= 1:
            return 0
        arr = [1]*n
        i = 2
        while i*i < n:
            if arr[i] == 1:
                j = 2
                while i*j < n:
                    arr[i*j] = 0
                    j+=1
            i+=1
        arr[0],arr[1] = 0,0
        return arr.count(1)
        
                
                
