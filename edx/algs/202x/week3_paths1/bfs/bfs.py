#Uses python3

import sys
import queue

def distance(adj, s, t):
    n = len(adj)
    l = [-1] * n

    q = queue.Queue(n)
    q.put(s)
    l[s] = 0
    while not q.empty():
        u = q.get()

        for i in range(len(adj[u])):
            v = adj[u][i]
            if l[v] >= 0:
                continue

            l[v] = l[u] + 1
            if v == t:
                return l[t]

            q.put(v)

    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    # input = '4 4 1 2 4 1 2 3 3 1 2 4'
    # input = '5 4 5 2 1 3 3 4 1 4 3 5'
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    s, t = data[2 * m] - 1, data[2 * m + 1] - 1
    print(distance(adj, s, t))
