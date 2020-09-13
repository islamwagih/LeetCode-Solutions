# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def binToDec(self,binNum):
        value = 0
        power = 0
        while binNum:
            value+=binNum%10 * 2 ** power
            power+=1
            binNum//=10
        return value
    def getDecimalValue(self, head):
        curr = head
        number = 0
        while curr:
            number = number*10 + curr.val
            curr = curr.next
        return self.binToDec(number)
