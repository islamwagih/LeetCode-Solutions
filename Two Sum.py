class Solution(object):
    def twoSum(self, nums, target):
        hashMap = {}
        for i in range(len(nums)):
            idx = hashMap.get(target-nums[i],-1)
            if idx > -1:
                    return [i,idx]
            hashMap[nums[i]] = i
    
        
        
            
