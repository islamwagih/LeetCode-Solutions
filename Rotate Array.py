class Solution(object):
    def rotate(self, nums, k):
        size = len(nums)
        if size <= 1 or k == 0:
            return
        if k > size:
            k-=size
        arr = [0]*k
        j = 0
        for i in range(size-k,size):
            arr[j] = nums[i]
            j+=1
        for i in range(size-k-1,-1,-1):
            temp = nums[i]
            nums[i] = nums[i+k]
            nums[i+k] = temp
        for i in range(k):
            nums[i] = arr[i]
        return nums

