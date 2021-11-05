# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        h = self.getHeight(root.left)
        l, r = 2 ** h, 2 ** (h + 1) - 1
        while l < r:
            k = (l + r + 1) // 2
            if self.isExists(root, h, k):
                l = k
            else:
                r = k - 1
        return l

    def getHeight(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + self.getHeight(root.left)

    def isExists(self, root: TreeNode, h: int, k: int) -> bool:
        b = 2 ** (h - 1)
        while b and root:
            if b & k:
                root = root.right
            else:
                root = root.left
            b >>= 1
        return root != None
