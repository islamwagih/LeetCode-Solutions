class Solution(object):
    def majorityElement(self, nums):
        size = len(nums)
        tracer = dict()
        for i in range(size):
            if tracer.get(nums[i],-1) == -1:
                tracer[nums[i]] = 1
            else:
                tracer[nums[i]]+=1
        for k in tracer:
            if tracer[k] > size//2:
                return k
       
        
