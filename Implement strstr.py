class Solution(object):
    def isSame(self,str1,str2):
        if str1 == str2:
            return True
        return False
    def strStr(self, haystack, needle):
        if not needle:
            return 0
        hayLen = len(haystack)
        needLen = len(needle)
        i = count = 0
        while i < hayLen-needLen+1:
            if haystack[i] == needle[0] and self.isSame(haystack[i:i+needLen],needle):
                return i
            i+=1
        return -1
