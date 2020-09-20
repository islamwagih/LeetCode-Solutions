class Solution(object):
    def rob(self, nums):
        if not nums:
            return 0
        size = len(nums)
        if size == 1:
            return nums[0]
        elif size == 2:
            return max(nums[0],nums[1])
        else:
            dp = [0]*size
            dp[0] = nums[0]
            dp[1] = max(nums[0],nums[1])
            for i in range(2,size):
                dp[i] = max(dp[i-1],dp[i-2]+nums[i])
            return dp[size-1]
        
