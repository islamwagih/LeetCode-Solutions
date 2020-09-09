class Solution(object):
    def maxSubArray(self, nums):
        maxSub = nums[0]
        currSub = nums[0]
        length = len(nums)
        for i in range(1,length):
            currSub = max(currSub+nums[i],nums[i])
            maxSub = max(maxSub,currSub)
        return maxSub
      
