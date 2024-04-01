class PriorityQueue(object):
    def __init__(self, arr=None):
        if arr is None:
            self.pq = []
        else:
            self.pq = arr
            self.heapify()
        return

    def heapify(self):
        n = self.size()
        for i in range((n - 2) // 2, -1, -1):
            self.sift_down(i)
        return

    def lchild(self, i):
        return 2 * i + 1

    def rchild(self, i):
        return 2 * i + 2

    def parent(self, i):
        return (i - 1) // 2

    def top(self):
        if not self.size():
            return None
        return self.pq[0]

    def size(self):
        return len(self.pq)

    def is_violate(self, p, c):
        if p < 0:
            return False
        if c >= self.size():
            return False
        return self.pq[p] > self.pq[c]

    def sift_down(self, i):
        n = self.size()

        while i < n:
            m = i
            l, r = self.lchild(i), self.rchild(i)
            if l < n and self.is_violate(m, l):
                m = l
            if r < n and self.is_violate(m, r):
                m = r
            if m != i:
                self.pq[m], self.pq[i] = self.pq[i], self.pq[m]
                i = m
            else:
                break
        return

    def sift_up(self, i):
        n = self.size()

        while 0 <= i < n:
            p = self.parent(i)
            if self.is_violate(p, i):
                self.pq[p], self.pq[i] = self.pq[i], self.pq[p]
                i = p
            else:
                break
        return

    def extract(self):
        if len(self.pq) <= 0:
            return None
        top = self.top()
        self.pq[0] = self.pq[-1]
        self.pq.pop()
        self.sift_down(0)
        return top

    def insert(self, data):
        self.pq.append(data)
        self.sift_up(self.size() - 1)
        return

    def __str__(self):
        return str(self.pq)

    def update(self, i, new_data):
        data = self.pq[i]
        # self.pq[i] = new_data
        # if self.is_violate(self.parent(i), i):
        #     self.
