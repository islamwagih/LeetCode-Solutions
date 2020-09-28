class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        
        set_s = set(s)  
        
        for char in set_s:
            if s.count(char) != t.count(char):
                return False
        return True
                
        
       
        
