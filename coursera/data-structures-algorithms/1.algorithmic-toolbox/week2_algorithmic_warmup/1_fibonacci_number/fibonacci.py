# Uses python3
def calc_fib(n):
    arr = [0, 1]
    for i in range(2, n + 1):
        arr.append(arr[i- 2] + arr[i -1 ])
    return arr[n]

n = int(input())
print(calc_fib(n))
