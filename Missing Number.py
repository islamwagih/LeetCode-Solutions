class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        hashTable = {num:True for num in nums}
        n = len(nums)
        for num in range(0,n+1):
            ans = hashTable.get(num, False)
            if not ans:
                return num
        return -1
