class Solution(object):
    def moveZeroes(self, nums):
        size = len(nums)
        moves = 0
        for i in range(size):
            if nums[i] == 0:
                moves+=1
            else:
                temp = nums[i]
                nums[i] = nums[i-moves]
                nums[i-moves] = temp
                   
                        
        
                
                
        
        
        
