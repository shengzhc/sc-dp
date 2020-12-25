"""

Bridge Pattern

Bridge is "analog" to contain/composition which extend the system
by compositing the new dimension/hierarchy in the original class, and
the reference is so-called "bridge".

1. Pattern is used when extend class in several dimensions.
2. Easy to switch underlying implementations(service).
3. A refined abstraction(client) can be defined in case of client extension.

"""


class IImplementation:
    def do_action1(self):
        pass

    def do_action2(self):
        pass


class ConcreteImplementation(IImplementation):
    def do_action1(self):
        print("ConcreteImplementation::do_action1()")

    def do_action2(self):
        print("ConcreteImplementation::do_action2()")


class Abstraction:
    def __init__(self, implementation):
        self.implementation = implementation

    def do_some_biz(self):
        self.implementation.do_action1()
        self.implementation.do_action2()


def client():
    impl = ConcreteImplementation()
    abst = Abstraction(impl)
    abst.do_some_biz()


if __name__ == "__main__":
    client()
