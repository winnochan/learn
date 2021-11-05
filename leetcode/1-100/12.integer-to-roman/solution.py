class Solution:
    def intToRoman(self, num: int) -> str:
        doc = {1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: "M"}
        bits = [num // 1000, (num // 100) % 10, (num // 10) % 10, num % 10]

        arr = []
        arr.append(bits[0] * doc[1000])

        for i in range(1, len(bits)):
            if not bits[i]:
                continue
            b = len(bits) - i - 1
            if bits[i] <= 3:
                arr.append(bits[i] * doc[10 ** b])
            elif bits[i] == 4:
                arr.append(doc[10 ** b] + doc[5 * (10 ** b)])
            elif bits[i] <= 8:
                arr.append(doc[5 * (10 ** b)] + (bits[i] - 5) * doc[10 ** b])
            else:
                arr.append(doc[10 ** b] + doc[10 ** (b + 1)])

        return "".join(arr)
