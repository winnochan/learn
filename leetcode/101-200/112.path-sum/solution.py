# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        result = False
        remain = sum - root.val
        if root.left or root.right:
            if root.left:
                result = result or self.hasPathSum(root.left, remain)
            if root.right:
                result = result or self.hasPathSum(root.right, remain)
        else:
            result = result or remain == 0
        return result
