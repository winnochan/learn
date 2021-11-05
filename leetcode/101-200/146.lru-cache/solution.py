class Node:
    def __init__(self, key=None, data=None, prev=None, next=None):
        self.key = key
        self.data = data
        self.prev = prev
        self.next = next


class LRUCache:
    def __init__(self, cap: int):
        self.cap = cap
        self.head = None
        self.tail = None
        self.table = {}
        return

    def moveToHead(self, key: int) -> None:
        node = self.table[key]
        if node == self.head:
            return
        if node == self.tail:
            self.tail = self.tail.prev
            self.tail.next = None
            node.prev = None
            node.next = self.head
            self.head.prev = node
            self.head = node
            return
        node.prev.next = node.next
        node.next.prev = node.prev
        node.prev = None
        node.next = self.head
        self.head.prev = node
        self.head = node
        return

    def get(self, key: int) -> int:
        if key not in self.table:
            return -1
        node = self.table[key]
        self.moveToHead(key)
        return node.data

    def put(self, key: int, value: int) -> None:
        if self.cap <= 0:
            return
        if key in self.table:
            node = self.table[key]
            node.data = value
            self.moveToHead(key)
        else:
            node = Node(key, value)
            self.table[key] = node
            if len(self.table) == 1:
                self.head = self.tail = node
            else:
                node.next = self.head
                self.head.prev = node
                self.head = node
            if len(self.table) > self.cap:
                tkey = self.tail.key
                del self.table[tkey]
                self.tail = self.tail.prev
                self.tail.next = None
        return


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
cache = LRUCache(2)

cache.put(1, 1)
cache.put(2, 2)
print(cache.get(1))
cache.put(3, 3)
print(cache.get(2))
cache.put(4, 4)
print(cache.get(1))
print(cache.get(3))
print(cache.get(4))
