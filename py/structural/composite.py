"""

Composite Pattern

1. Use to solve data of tree-like structure with client-consumable common
   interface.
2. Leaf vs Container.

"""


class IComponent:
    def do_some_action(self):
        pass


class ConcreteComponentLeaf(IComponent):
    def __init__(self, value):
        self.value = value

    def do_some_action(self):
        print("ConcreteComponentLeaf[{}]::do_some_action()".format(self.value))


class ComponentContainer(IComponent):
    def __init__(self):
        self.children = []

    def addComponent(self, c):
        if c not in self.children:
            self.children.append(c)

    def removeComponent(self, c):
        if c in self.children:
            self.children.remove(c)

    def do_some_action(self):
        for c in self.children:
            c.do_some_action()


def client():
    container1 = ComponentContainer()
    container2 = ComponentContainer()
    container1.addComponent(ConcreteComponentLeaf('a'))
    container1.addComponent(ConcreteComponentLeaf('b'))
    container1.addComponent(container2)
    container2.addComponent(ConcreteComponentLeaf('c'))
    container2.addComponent(ConcreteComponentLeaf('d'))
    container1.do_some_action()


if __name__ == "__main__":
    client()
