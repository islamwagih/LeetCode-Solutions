class Solution(object):
    def oneChar(self,letter):
        return ord(letter) - ord('A') + 1
    def titleToNumber(self, s):
        size = len(s)
        if size == 1:
            return self.oneChar(s)
        total = 0
        exp = 0
        base = 26
        i = -1
        while i >= -size:
            total = total + self.oneChar(s[i])*base**exp
            exp+=1
            i-=1
        return total
    
        

    
        
        
        
