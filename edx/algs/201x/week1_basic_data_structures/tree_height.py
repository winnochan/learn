# python3

import sys
import threading


def compute_height(n, parents):
    # Replace this code with a faster implementation

    not_leaves = [0] * n
    max_height = 0
    for vertex in range(n):
        if not_leaves[vertex]:
            continue

        height = 0
        current = vertex
        while current != -1:
            height += 1
            current = parents[current]
            if height <= not_leaves[current]:
                break
            if current >= 0:
                not_leaves[current] = height
        max_height = max(max_height, height)
    # print(parents, not_leaves)
    return max_height


def main():
    # n = int(input())
    # parents = list(map(int, input().split()))
    n = 5
    parents = list(map(int, '4 -1 4 1 1'.split()))
    print(compute_height(n, parents))


# In Python, the default limit on recursion depth is rather low,
# so raise it here for this problem. Note that to take advantage
# of bigger stack, we have to launch the computation in a new thread.
sys.setrecursionlimit(10**7)  # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size
threading.Thread(target=main).start()
