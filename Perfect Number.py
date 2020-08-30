from math import sqrt    
class Solution(object):
    def checkPerfectNumber(self, num):
        if num <= 1 or num%2 != 0:
            return False
        i,sums = 1,0
        last = int(sqrt(num))
        while i <= last:
            if num%i == 0:
                if i > 1:
                    secTerm = num//i
                    sums+=secTerm
                sums+=i
            if sums > num:
                return False
            i+=1
        if sums == num :
            return True
        return False
