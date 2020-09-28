class Solution(object):
    def isAnagram(self, s, t):
        sSize = len(s)
        tSize = len(t)
        if sSize != tSize:
            return False
        hashTable = dict()
        hashTable2 = dict()
        for i in range(sSize):
            if hashTable.get(s[i],-1) == -1:
                hashTable[s[i]] = 1
            else:
                hashTable[s[i]] += 1
            if hashTable2.get(t[i],-1) == -1:
                hashTable2[t[i]] = 1
            else:
                hashTable2[t[i]] += 1
        for i in range(tSize):
            if hashTable.get(t[i], -1) == -1:
                return False
            else:
                if hashTable[t[i]] != hashTable2[t[i]]:
                    return False
        return True
