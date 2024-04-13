# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        arr = []
        self.dfs(root, arr)
        for i in range(len(arr) - 1):
            if arr[i] >= arr[i+1]:
                return False
        return True

    def dfs(self, root: TreeNode, arr: List[int]) -> None:
        if not root:
            return
        self.dfs(root.left, arr)
        arr.append(root.val)
        self.dfs(root.right, arr)
