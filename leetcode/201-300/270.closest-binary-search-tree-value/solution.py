# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        if not root:
            return
        value = root.val
        closest = abs(root.val - target)
        while root:
            diff = abs(root.val - target)
            if diff < closest:
                value = root.val
                closest = diff
            if root.val > target:
                root = root.left
            else:
                root = root.right
        return value
