class Solution(object):
    def moveZeroes(self, nums):
        size = len(nums)
        anchor = 0
        for exp in range(size):   
            if nums[exp] != 0:
                nums[exp],nums[anchor] = nums[anchor],nums[exp]
                anchor+=1
                        
        
                
                
        
        
        
