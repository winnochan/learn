# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        digits = []
        nums = []
        self.dfs(root, digits, nums)
        return sum(nums)

    def dfs(self, root: TreeNode, digits: List[str], nums: List[int]):
        if not root:
            return
        digits.append(str(root.val))
        self.dfs(root.left, digits, nums)
        self.dfs(root.right, digits, nums)
        if not root.left and not root.right:
            nums.append(int("".join(digits)))
        digits.pop()
        return
