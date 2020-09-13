# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        curr = head
        prv = nex = None
        while curr:
            nex = curr.next
            curr.next = prv
            prv = curr
            curr = nex
        return prv
            

                
                
       
        
