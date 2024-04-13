class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        l = len(arr)
        temp = [[self.countBits(arr[i]), arr[i]] for i in range(l)]
        temp.sort()
        return [temp[i][1] for i in range(l)]

    def countBits(self, num: int) -> int:
        count = 0
        while num > 0:
            if num % 2 == 1:
                count += 1
            num //= 2
        return count
