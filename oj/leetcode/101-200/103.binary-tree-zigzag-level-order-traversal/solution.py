# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        ret = []
        if not root:
            return ret

        queue = [root]
        i = 0
        end = len(queue)
        zig = True
        while i < end:
            temp = []
            while i < end:
                temp.append(queue[i].val)
                if queue[i].left:
                    queue.append(queue[i].left)
                if queue[i].right:
                    queue.append(queue[i].right)
                i += 1
            if temp:
                if zig:
                    ret.append(temp)
                else:
                    ret.append(temp[::-1])
            end = len(queue)
            zig = not zig
        return ret
