class Solution(object):
    def singleNumber(self, nums):
        hashMap = {}
        for i in nums:
            res = hashMap.get(i,-1)
            if res == -1:
                hashMap[i] = 1
            else:
                hashMap[i]+=1
        for i in hashMap:
            if hashMap[i] == 1:
                return i
        return -1
       
        
