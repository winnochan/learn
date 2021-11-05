# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return self.getHeight(root) >= 0

    def getHeight(self, root: TreeNode) -> int:
        if not root:
            return 0
        l = self.getHeight(root.left)
        r = self.getHeight(root.right)
        if l >= 0 and r >= 0 and abs(l - r) <= 1:
            return max(l, r) + 1
        return -1
