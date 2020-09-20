# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def DFSinorder(self,node,data):
        if(node.left):
            self.DFSinorder(node.left,data)
        data.append(node.val)
        if(node.right):
            self.DFSinorder(node.right,data)
        return data
    def isValidBST(self, root):
        if not root:
            return True
        arr = self.DFSinorder(root,[])
        hashMap = dict()
        for i in arr:
            if hashMap.get(i,0):
                return False
            hashMap[i] = 1
        if arr == sorted(arr):
            return True
        return False

