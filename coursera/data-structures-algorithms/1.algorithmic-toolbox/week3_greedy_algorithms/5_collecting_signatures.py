# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    segments.sort(key= lambda s: (s.end, s.start))
    # print(segments)
    points = []
    #write your code here
    for s in segments:
        if not len(points):
            points.append(s.end)
        elif s.start > points[-1]:
            points.append(s.end)
    return points

if __name__ == '__main__':
    input = sys.stdin.read()
#     input = '''4
# 4 7
# 1 3
# 2 5
# 5 6'''
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    print(*points)
