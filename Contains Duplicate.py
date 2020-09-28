class Solution(object):
    def containsDuplicate(self, nums):
        hashTable = dict()
        size = len(nums)
        for i in range(size):
            if hashTable.get(nums[i],False):
                return True
            hashTable[nums[i]] = True
        return False
        
