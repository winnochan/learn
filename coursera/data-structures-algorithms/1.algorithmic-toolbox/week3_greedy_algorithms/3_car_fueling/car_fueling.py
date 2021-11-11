# python3
import sys


def compute_min_refills(d, m, stops):
    n = len(stops)
    return -1

if __name__ == '__main__':
    d, m, _, *stops = map(int, sys.stdin.read().split())
    print(compute_min_refills(d, m, stops))
