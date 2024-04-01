#Uses python3

import sys
import queue


def bipartite(adj):
    n = len(adj)
    c = [-1] * n
    q = queue.Queue(n)

    q.put(0)
    c[0] = 0

    while not q.empty():
        u = q.get()

        for v in adj[u]:
            if c[v] >= 0:
                if c[v] == c[u]:
                    return 0
                continue

            c[v] = 0 if c[u] > 0 else 1
            q.put(v)

    return 1


if __name__ == '__main__':
    input = sys.stdin.read()
    # input = '4 4 1 2 4 1 2 3 3 1'
    # input = '5 4 5 2 4 2 3 4 1 4'
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(bipartite(adj))
