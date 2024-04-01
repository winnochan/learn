#Uses python3

import sys


def detect_cycle_by_stack(adj):
    n = len(adj)
    visited = [0] * n
    stack = [0] * n

    def is_cyclic(adj, v, visited, stack):
        if not visited[v]:
            visited[v] = 1
            stack[v] = 1
            for i in range(len(adj[v])):
                w = adj[v][i]
                if not visited[w] and is_cyclic(adj, w, visited, stack):
                    return 1
                if stack[w]:
                    return 1
        stack[v] = 0
        return 0

    for i in range(n):
        if is_cyclic(adj, i, visited, stack):
            return 1

    return 0


def acyclic(adj):
    return detect_cycle_by_stack(adj)


if __name__ == '__main__':
    input = sys.stdin.read()
    # input = '4 4 1 2 4 1 2 3 3 1'
    # input = '5 7 1 2 2 3 1 3 3 4 1 4 2 5 3 5'
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(acyclic(adj))
