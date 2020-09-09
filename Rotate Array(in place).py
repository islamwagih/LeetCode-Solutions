class Solution(object):
    def swap(self,a,b):
        return b,a
    def reverse(self,arr):
        size = len(arr)
        last = size-1
        mid = size//2
        for first in range(mid):
            arr[first],arr[last] = self.swap(arr[first],arr[last])
            last-=1
        return arr
    def rotate(self, nums, k):
        size = len(nums)
        if size <= 1 or k == 0 or k%size == 0:
            return
        if k > size:
            while k > size:
                k-=size
        nums = self.reverse(nums)
        nums[:k] = self.reverse(nums[:k])
        nums[k:] = self.reverse(nums[k:])

