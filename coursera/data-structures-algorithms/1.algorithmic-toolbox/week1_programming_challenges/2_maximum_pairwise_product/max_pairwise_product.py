def max_pairwise_product(numbers):
    n = len(numbers)
    first = 0
    # max_product = numbers[j] * numbers[k]
    for i in range(n):
        if numbers[i] > numbers[first]:
            first = i
    second = 0 if first > 0 else 1
    for i in range(n):
        if i != first and numbers[i] > numbers[second]:
            second = i
    return numbers[first] * numbers[second]

if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))
