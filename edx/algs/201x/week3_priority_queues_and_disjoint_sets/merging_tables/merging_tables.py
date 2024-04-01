# python3


class Database:
    def __init__(self, row_counts):
        self.row_counts = row_counts
        self.max_row_count = max(row_counts)
        n_tables = len(row_counts)
        self.ranks = [1] * n_tables
        self.parents = list(range(n_tables))

    def merge(self, src, dst):
        src_parent = self.get_parent(src)
        dst_parent = self.get_parent(dst)

        if src_parent == dst_parent:
            return False

        if self.ranks[src_parent] <= self.ranks[dst_parent]:
            self.parents[src_parent] = dst_parent
            # self.parents[src] = dst_parent
            self.row_counts[dst_parent] += self.row_counts[src_parent]
            if self.row_counts[dst_parent] > self.max_row_count:
                self.max_row_count = self.row_counts[dst_parent]

            if self.ranks[src_parent] == self.ranks[dst_parent]:
                self.ranks[dst_parent] += 1
        else:
            self.parents[dst_parent] = src_parent
            # self.parents[dst] = src_parent
            self.row_counts[src_parent] += self.row_counts[dst_parent]
            if self.row_counts[src_parent] > self.max_row_count:
                self.max_row_count = self.row_counts[src_parent]

        return True

    def _get_root(self, table):
        while table != self.parents[table]:
            table = self.parents[table]
        return table

    def get_parent(self, table):
        # find parent and compress path
        root = self._get_root(table)
        self.parents[table] = root
        return root


def main():
    n_tables, n_queries = map(int, input().split())
    counts = list(map(int, input().split()))
    assert len(counts) == n_tables
    db = Database(counts)
    for i in range(n_queries):
        dst, src = map(int, input().split())
        db.merge(dst - 1, src - 1)
        print(db.max_row_count)


if __name__ == "__main__":
    main()
