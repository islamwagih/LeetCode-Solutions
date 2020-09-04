class Solution(object):
    def sortArrayByParity(self, A):
        size = len(A)
        arr = [-1]*size
        evenIdx = 0
        oddIdx = size-1
        i = 0
        while evenIdx <= oddIdx:
            if A[i] % 2 == 0:
                arr[evenIdx] = A[i]
                evenIdx+=1
            else:
                arr[oddIdx] = A[i]
                oddIdx-=1
            i+=1
        return arr
        
            

        
        
