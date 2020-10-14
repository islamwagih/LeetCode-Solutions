class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        resList = list()
        cache = dict()
        for num in nums1:
            cache[num] = cache.get(num, 0) + 1
        for num in nums2:
            if cache.get(num, 0) >= 1:
                resList.append(num)
                cache[num] -= 1
        return resList
