#Uses python3

import sys

sys.setrecursionlimit(200000)


def reverse(adj):
    n = len(adj)

    radj = [[] for _ in range(n)]
    for i in range(n):
        for j in range(len(adj[i])):
            radj[adj[i][j]].append(i)

    return radj


def dfs(adj, v, mark=None, *, post=None):
    n = len(adj[v])
    if mark is None:
        mark = [False] * n

    mark[v] = True

    for i in range(n):
        if mark[adj[v][i]]:
            continue

        dfs(adj, adj[v][i], mark, post=post)

    if post is not None:
        post.append(v)

    return post


def get_post(adj):
    n = len(adj)
    mark = [False] * n
    post = []

    for i in range(n):
        if mark[i]:
            continue

        dfs(adj, i, mark, post=post)

    return post


def number_of_strongly_connected_components(adj):
    post = get_post(reverse(adj))
    # print(post)

    count = 0
    mark = [False] * n
    for i in range(n):
        if mark[post[-1 - i]]:
            continue

        dfs(adj, post[-1 - i], mark)
        # print(mark)
        count += 1

    return count


if __name__ == '__main__':
    input = sys.stdin.read()
    # input = '4 4 1 2 4 1 2 3 3 1'
    # input = '4 3 1 2 3 2 4 3'
    # input = '5 7 2 1 3 2 3 1 4 3 4 1 5 2 5 3'
    # input = '10 20 7 8 4 10 3 2 1 3 4 9 2 6 8 3 8 2 6 1 6 10 10 6 1 4 3 8 1 5 8 9 5 3 3 4 5 1 8 5 8 4'
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(number_of_strongly_connected_components(adj))
