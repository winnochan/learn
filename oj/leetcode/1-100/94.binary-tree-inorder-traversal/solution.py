# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        result = []
        stack = [root]
        while stack:
            top = stack[-1]
            if top.left:
                stack.append(top.left)
                top.left = None
                continue
            stack.pop()
            result.append(top.val)
            if top.right:
                stack.append(top.right)
                top.right = None
                continue
        return result
