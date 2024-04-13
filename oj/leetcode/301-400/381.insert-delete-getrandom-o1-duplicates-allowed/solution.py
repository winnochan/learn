import random


class RandomizedCollection:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.array = []
        self.table = {}
        return

    def insert(self, value: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        index = len(self.array)
        self.array.append(value)
        if value not in self.table:
            self.table[value] = set([index])
            # print(self.array)
            return True
        else:
            self.table[value].add(index)
            # print(self.array)
            return False

    def remove(self, value: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if value not in self.table:
            return False

        valueIndexSet = self.table[value]
        if value == self.array[-1]:
            self.table[value].remove(len(self.array) - 1)
            if not self.table[value]:
                del self.table[value]
            self.array.pop()
            return True

        index = valueIndexSet.pop()
        if not valueIndexSet:
            del self.table[value]
        final = self.array[-1]
        self.array[index] = final
        finalIndexSet = self.table[final]
        finalIndexSet.remove(len(self.array) - 1)
        finalIndexSet.add(index)
        self.array.pop()

        # print(self.array)
        # print(self.table)
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        index = random.randint(0, len(self.array) - 1)
        return self.array[index]


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
