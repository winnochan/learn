#Uses python3

import sys

visited = {}

def reach(adj, x, y):
    #write your code here
    # print(adj, x, y)

    if x == y:
        return 1

    if x in visited:
        return 0

    visited[x] = 1
    vertices = adj[x]
    for i in range(len(vertices)):
        v = vertices[i]
        if v in visited:
            continue
        r = reach(adj, v, y)
        if r:
            return r
    return 0


if __name__ == '__main__':
    input = sys.stdin.read()
    # input = '4 4 1 2 3 2 4 3 1 4 1 4'
    # input = '4 2 1 2 3 2 1 4'
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    # print(data)
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    # print(edges)
    x, y = data[2 * m:]
    adj = [[] for _ in range(n)]
    x, y = x - 1, y - 1
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(reach(adj, x, y))
