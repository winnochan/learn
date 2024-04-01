# python3

import random


# Rabin Karp's Algorithms
def poly_hash(text, begin, length, a, p, ap, last=None):
    '''
    h(a, p) = sum(text[begin + length - 1] * a ^ (length - 1),
    text[begin + length - 2] * a ^ (length - 2), ..., text[begin])
    '''
    ret = 0
    if not last:
        for i in range(begin + length - 1, begin - 1, -1):
            ret = (ret + (ord(text[i]) * a) % p) % p
    else:
        ret = (((last - (ord(text[begin - 1]) * ap) % p + p) * a) % p +
               ord(text[begin + length - 1]) % p) % p
    return ret


def poly_ap(a, p, length):
    ret = 0
    for i in range(length):
        ret = (ret + a) % p
    return ret


def read_input():
    return (input().rstrip(), input().rstrip())


def print_occurrences(output):
    print(' '.join(map(str, output)))


def get_occurrences(pattern, text):
    # p = 100000007
    # a = random.randint(0, p - 1)
    p = 7
    a = 3
    length = len(pattern)
    ap = poly_ap(a, p, length)

    pattern_hash = poly_hash(pattern, 0, length, a, p, ap)
    print(a, p, length, ap, pattern_hash)

    last_hash = None
    ret = []
    for i in range(len(text) - length + 1):
        last_hash = poly_hash(text, i, length, a, p, ap, last_hash)
        print(i, last_hash)
        if last_hash != pattern_hash:
            continue
        if pattern == text[i:i + length]:
            ret.append(i)

    return ret


if __name__ == '__main__':
    print_occurrences(get_occurrences(*read_input()))
