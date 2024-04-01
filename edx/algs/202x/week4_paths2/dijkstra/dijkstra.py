#Uses python3

import sys
import json
import queue
import heapq


class Vertex(object):
    def __init__(self, vid, adj, dis=float('inf')):
        self.vid = vid
        self.adj = adj
        self.dis = dis
        return

    def __lt__(self, other):
        return self.lt(other.dis)

    def lt(self, dis):
        return self.dis < dis

    def __le__(self, other):
        return self.le(other.dis)

    def le(self, dis):
        return self.dis <= dis

    def __eq__(self, other):
        return self.eq(other.dis)

    def eq(self, dis):
        return self.dis == dis

    def __repr__(self):
        return str({'adj': self.adj, 'dis': self.dis, 'vid': self.vid})


class PriorityQueue(object):
    def __init__(self, q=None):
        if q is None:
            self.queue = []
        else:
            self.queue = q
            heapq.heapify(self.queue)
        self.index = {self.queue[i].vid: i for i in range(len(self.queue))}
        return

    def __repr__(self):
        return str({'queue': self.queue, 'index': self.index})

    def _parent(self, i):
        return (i - 1) // 2

    def _lchild(self, i):
        return 2 * i + 1

    def _rchild(self, i):
        return 2 * i + 2

    def _siftup(self, i):
        while i > 0:
            p = self._parent(i)
            vi = self.queue[i]
            vp = self.queue[p]
            if vp <= vi:
                break
            self.queue[i] = vp
            self.queue[p] = vi
            self.index[vi.vid] = p
            self.index[vp.vid] = i
            i = p
        return

    def _siftdown(self, i):
        n = self.size()
        while i < n:
            m = i
            l = self._lchild(i)
            r = self._rchild(i)

            vi = self.queue[i]
            if l < n:
                vl = self.queue[l]
                if vl < vi:
                    m = l

            vm = self.queue[m]
            if r < n:
                vr = self.queue[r]
                if vr < vm:
                    m = r
            vm = self.queue[m]
            if m == i:
                break
            self.queue[i] = vm
            self.queue[m] = vi
            self.index[vi.vid] = m
            self.index[vm.vid] = i
            i = m
        return

    def size(self):
        return len(self.queue)

    def get(self, vid):
        if vid not in self.index:
            return None
        return self.queue[self.index[vid]]

    def top(self):
        if not self.size():
            return None
        return self.queue[0]

    def pop(self):
        n = self.size()
        if not n:
            return None
        v = self.queue[0]
        if n == 1:
            self.queue = []
            self.index = {}
            return v
        t = self.queue.pop()
        self.queue[0] = t
        # print(v, v.vid, t, t.vid, self.index)
        del self.index[v.vid]
        self.index[t.vid] = 0
        self._siftdown(0)
        return v

    def put(self, v):
        self.queue.append(v)
        self._siftup(self.size() - 1)
        return

    def popput(self, v):
        t = self.top()
        self.queue[0] = v
        self._siftdown(0)
        return t

    def update(self, vid, dis):
        i = self.index[vid]
        v = self.queue[i]
        if v.lt(dis):
            v.dis = dis
            self._siftdown(i)
        else:
            v.dis = dis
            self._siftup(i)
        return


def distance(adj, cost, s, t):
    n = len(adj)
    q = []
    for i in range(n):
        dis = 0 if s == i else float('inf')
        # print(i, adj[i], cost[i])
        v = Vertex(i, {adj[i][j]: cost[i][j] for j in range(len(adj[i]))}, dis)
        q.append(v)

    pq = PriorityQueue(q)
    # print(s, t)
    # print(pq)
    while pq.size():
        u = pq.pop()
        if u.vid == t:
            return u.dis if u.dis < float('inf') else -1
        for vid in u.adj:
            w = u.adj[vid]
            v = pq.get(vid)
            if v is None:
                continue
            dis = u.dis + w
            if dis < v.dis:
                pq.update(vid, dis)
        # print(pq)
    return -1


if __name__ == '__main__':
    input = sys.stdin.read()
    # input = '4 4 1 2 1 4 1 2 2 3 2 1 3 5 1 3'
    # input = '5 9 1 2 4 1 3 2 2 3 2 3 2 1 2 4 2 3 5 4 5 4 1 2 5 3 3 4 4 1 5'
    # input = '3 3 1 2 7 1 3 5 2 3 2 3 2'
    # input = '10 9 1 2 1 5 6 1 6 7 1 8 9 1 9 10 1 3 4 1 7 8 1 4 5 1 2 3 1 1 10'
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(
        zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    data = data[3 * m:]
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    s, t = data[0] - 1, data[1] - 1
    print(distance(adj, cost, s, t))
