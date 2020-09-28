# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        if not root:
            return []
        from collections import deque
        result = []
        stack = deque()
        while True:
            if root:
                stack.append(root)
                root = root.left
            else:
                if len(stack) == 0:
                    break
                node = stack.pop()
                result.append(node.val)
                root = node.right
        return result
                
        
        
