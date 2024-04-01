class Node(object):
    def __init__(self, data, lchild=None, rchild=None, parent=None):
        super(Node, self).__init__()
        self.value = value
        self.lchild = lchild
        self.rchild = rchild
        self.parent = parent
        return


class BinarySearchTree(object):
    def __init__(self, root=None):
        self.root = root
        return

    def find_node(self, value, node=self.root):
        if node is None:
            return node

        if node.value == value:
            return node
        if node.value > value:
            if node.lchild is None:
                return node
            return self.find_node(value, node.lchild)
        if node.value < value:
            if node.rchild is None:
                return node
            return self.find_node(value, node.rchild)

    def prev_node(self, node=self.root):
        if node is None:
            return None
        if node.lchild is not None:
            temp = node.lchild
            while temp.rchild is not None:
                temp = temp.rchild
            return temp
        else:
            value = node.value
            temp = node.parent
            while temp is not None:
                if temp.value < value:
                    break
                temp = temp.parent
            return temp

    def next_node(self, node=self.root):
        if node is None:
            return None

        if node.rchild is not None:
            temp = node.rchild
            while temp.lchild is not None:
                temp = temp.lchild
            return temp
        else:
            value = node.value
            temp = node.parent
            while temp is not None:
                if temp.value > value:
                    break
                temp = temp.parent
            return temp

    def search(self, min_value, max_value, root=self.root):
        l = []
        node = self.find_node(min_value, root)
        while node.value <= max_value:
            if node.value >= min_value:
                l.append(node)
            node = self.next_node(node)
        return l

    def insert(self, value, root=self.root):
        node = self.find_node(value, root)
        if value > node.value:
            new_node = Node(value, None, node.rchild, node)
            node.rchild = new_node
        else:
            new_node = Node(value, node.lchild, None, node)
            node.lchild = new_node

    def delete(self, value, root=self.root):
        node = self.find_node(value, root)
        if node is None or node.value != value:
            return
        if node.rchild is None:
            node.parent.left = node.lchild
        else:
            next_node = self.next_node(node)
            node.value = next_node.value
            next_node.parent.lchild = next_node.rchild
