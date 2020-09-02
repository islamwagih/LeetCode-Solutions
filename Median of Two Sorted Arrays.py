class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        lenLeft = len(nums1)
        lenRight = len(nums2)
        arr = [0]*(lenLeft+lenRight)
        lptn = rptn = i = 0
        size = lenLeft+lenRight
        while lptn < lenLeft and rptn < lenRight:
            if(nums1[lptn] < nums2[rptn]):
                arr[i] = nums1[lptn]
                lptn+=1
            else:
                arr[i] = nums2[rptn]
                rptn+=1
            i+=1
        if lptn < lenLeft:
            while lptn < lenLeft:
                arr[i] = nums1[lptn]
                i+=1
                lptn+=1
        else:
            while rptn < lenRight:
                arr[i] = nums2[rptn]
                i+=1
                rptn+=1
        mid = size//2
        if size%2 == 0:
            return (arr[mid]+arr[mid-1])/2.0
        return arr[mid]
            
        
