class Solution(object):
    def firstUniqChar(self,s):
        size = len(s)
        dic = {}
        
        for idx in range(size):
            val = dic.get(s[idx],-1)
            if val == -1:
                dic[s[idx]] = idx
            else:
                dic[s[idx]] = size
    
        minIdx = size
        for key in dic:
            if dic[key] < minIdx:
                minIdx = dic[key]
        if minIdx == size:
            return -1
        
        return minIdx
      
