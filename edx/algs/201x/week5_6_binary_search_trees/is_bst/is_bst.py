#!/usr/bin/python3

import sys, threading

sys.setrecursionlimit(10**7)  # max depth of recursion
threading.stack_size(2**28)  # new thread will get stack of such size


def IsBinarySearchTree(tree, index=0, m=float('-inf'), M=float('inf')):
    if not tree or index < 0:
        return True

    key, left, right = tree[index]
    if key <= m or key >= M:
        return False
    return IsBinarySearchTree(tree, left, m, key) and IsBinarySearchTree(
        tree, right, key, M)


def main():
    nodes = int(sys.stdin.readline().strip())
    tree = []
    for i in range(nodes):
        tree.append(list(map(int, sys.stdin.readline().strip().split())))
    if IsBinarySearchTree(tree):
        print("CORRECT")
    else:
        print("INCORRECT")


threading.Thread(target=main).start()
