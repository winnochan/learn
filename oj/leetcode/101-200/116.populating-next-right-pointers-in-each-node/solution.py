#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return root
        self.dfs(root)
        return root

    def dfs(self, left, right=None):
        if not left:
            return
        left.next = right
        self.dfs(left.left, left.right)
        if right:
            self.dfs(left.right, right.left)
        else:
            self.dfs(left.right, None)
