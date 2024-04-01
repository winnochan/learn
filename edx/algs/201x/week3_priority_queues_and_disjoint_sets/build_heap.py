# python3


def build_heap(data):
    """Build a heap from ``data`` inplace.

    Returns a sequence of swaps performed by the algorithm.
    """
    # The following naive implementation just sorts the given sequence
    # using selection sort algorithm and saves the resulting sequence
    # of swaps. This turns the given array into a heap, but in the worst
    # case gives a quadratic number of swaps.
    #
    # TODO: replace by a more efficient implementation
    swaps = []
    n = len(data)

    for i in range((n - 2) // 2, -1, -1):
        j = i
        while j < n:
            m = j
            l = 2 * m + 1
            r = l + 1
            if l < n and data[l] < data[m]:
                m = l
            if r < n and data[r] < data[m]:
                m = r
            if m != j:
                swaps.append((j, m))
                data[j], data[m] = data[m], data[j]
                j = m
            else:
                break

    return swaps


def main():
    # n = int(input())
    # data = list(map(int, input().split()))
    # assert len(data) == n
    data = list(map(int, '5 4 3 2 1'.split()))

    swaps = build_heap(data)

    print(len(swaps))
    for i, j in swaps:
        print(i, j)


if __name__ == "__main__":
    main()
