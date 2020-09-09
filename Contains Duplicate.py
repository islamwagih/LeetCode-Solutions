class Solution(object):
    def containsDuplicate(self, nums):
        hashSet = set()
        size = len(nums)
        for i in range(size):
            if nums[i] in hashSet:
                return True
            hashSet.add(nums[i])
        return False
        
