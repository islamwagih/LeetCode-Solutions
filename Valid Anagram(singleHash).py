class Solution(object):
    def isAnagram(self, s, t):
        hashTable = dict()
        for i in s:
            if hashTable.get(i,-1) == -1:
                hashTable[i] = 1
            else:
                hashTable[i] += 1
        for i in t:
            if hashTable.get(i,-1) == -1:
                return False
            else:
                hashTable[i] -= 1
        for i in hashTable:
            if hashTable[i] != 0:
                return False
        return True
                
        
       
        
