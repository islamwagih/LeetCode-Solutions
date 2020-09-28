# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def DFSinorder(self,root,data):
        if root.left:
            self.DFSinorder(root.left,data)
        data.append(root.val)
        if root.right:
            self.DFSinorder(root.right,data)
        return data
    def inorderTraversal(self, root):
        if not root:
            return []
        return self.DFSinorder(root,[])
        
        
