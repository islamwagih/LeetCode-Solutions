
class Solution(object):
    def twoSum(self, nums, target):
        checkSet = set()
        idxLst = []
        for i in nums:
            checkSet.add(i)
        for i in range(len(nums)):
            diff = abs(nums[i]-target)
            if diff in checkSet:
                nextElement = diff
                idxLst.append(i)
                break
        for i in range(len(nums)):
            if nums[i] == nextElement:
                idxLst.append(i)
                break
        return idxLst
        
        
a = Solution()
print(a.twoSum([15,9,0,4,3,6],10))

def twoSum(numbers, target):
    dic = {}
    for i, num in enumerate(numbers):
        if target-num in dic:
            return [dic[target-num], i]
        dic[num] = i

def twoSumSet(numbers,target):
    checkSet = set()
    for element in numbers:
        diff = target-element
        if diff in checkSet:
            return [element,diff]
        checkSet.add(element)
    return -1

            
            
 
