class Node:
    def __init__(self, label):
        self.label = label
        self.parent = None
        self.children = []

    def add(self, child):
        assert child.parent is None
        self.children.append(child)
        child.parent = self

    def __repr__(self):
        return f'<{self.label}, parent={self.parent}, children={self.children}>'

    def is_root(self):
        return self.parent is None
