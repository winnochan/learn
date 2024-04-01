#Uses python3

import sys


def dfs(adj, used, order, x):
    #write your code here
    if used[x]:
        return
    used[x] = 1
    for i in range(len(adj[x])):
        if used[adj[x][i]]:
            continue
        dfs(adj, used, order, adj[x][i])
        # order.append(adj[x][i])
    order.append(x)
    return


def toposort(adj):
    used = [0] * len(adj)
    order = []
    for i in range(len(adj)):
        dfs(adj, used, order, i)
    #write your code here
    return order[::-1]


if __name__ == '__main__':
    input = sys.stdin.read()
    # input = '4 1 3 1'
    # input = '4 3 1 2 4 1 3 1'
    # input = '5 7 2 1 3 2 3 1 4 3 4 1 5 2 5 3'
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    order = toposort(adj)
    for x in order:
        print(x + 1, end=' ')
