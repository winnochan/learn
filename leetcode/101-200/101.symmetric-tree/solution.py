# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        self.process(root.right)
        return self.isEqual(root.left, root.right)

    def process(self, root: TreeNode) -> TreeNode:
        if not root:
            return
        root.left, root.right = root.right, root.left
        self.process(root.left)
        self.process(root.right)

    def isEqual(self, node1: TreeNode, node2: TreeNode) -> bool:
        if not node1:
            return node2 == None
        if not node2:
            return node1 == None
        return node1.val == node2.val and self.isEqual(node1.left, node2.left) and self.isEqual(node1.right, node2.right)
