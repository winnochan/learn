class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.s1 = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.s1.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.s1:
            return self.s1.pop()

    def top(self) -> int:
        """
        Get the top element.
        """
        if self.s1:
            return self.s1[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.s1



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
