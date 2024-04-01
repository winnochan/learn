#Uses python3
import sys
import math
import heapq

def minimum_distance(edges, n):
    # total = 0
    # count = 0
    # marks = [0] * n
    # heapq.heapify(edges)
    # print(edges)

    # while len(edges):
    #     v = heapq.heappop(edges)
    #     if count >= n:
    #         break
    #     if marks[v[1]] and marks[v[2]]:
    #         continue
    #     total += v[0]
    #     count += 1
    #     if not marks[v[1]]:
    #         marks[v[1]] = 1
    #     if not marks[v[2]]:
    #         marks[v[2]] = 1
    #     print(total, count)

    #write your code here
    return total


def gen_edges(n, x, y):
    edges = []
    for i in range(n - 1):
        for j in range(i + 1, n):
            edges.append(
                [math.sqrt((x[i] - x[j])**2 + (y[i] - y[j])**2), i, j])

    return edges


if __name__ == '__main__':
    # input = sys.stdin.read()
    # input = '4 0 0 0 1 1 0 1 1'
    input = '5 0 0 0 2 1 1 3 0 3 2'
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    print("{0:.9f}".format(minimum_distance(gen_edges(n, x, y), n)))
