class Solution(object):
    def lengthOfLongestSubstring(self, s):
        low = longest = 0
        length = len(s)
        while low < length:
            high = low
            checkSet = set()
            currLong = 0
            while high < length and s[high] not in checkSet:
                checkSet.add(s[high])
                currLong+=1
                high+=1
            longest = max(longest,currLong)
            low+=1
        return longest
        