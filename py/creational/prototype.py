"""

Prototype Pattern

1. Prototype is "analog" to self-cloning implementation which hides
   the internal details of obj to allow client not to worry much about
   how to get a brand new instance of the "same" obj as original.
2. Inheritance is not required, but subclass should utilize the parent's
   constructor and initializer (+ any setter methods) to construct new
   cloned obj which covers the parent's fields and new fields in subclass.
3. Prototype registry is a convenient way to allow client to have easy access
   to create brand new obj based upon old-created data. Ths is optional, but
   can be a "global"-accessible repo to make all clients consistent in using
   the "same" component across different places of the same program.


"""


class IPrototype:
    def clone():
        print("Abstract method for cloning obj")


class ConcretePrototype(IPrototype):
    def __init__(self, rc):
        self.rc = rc

    def clone(self):
        print("Cloning ConcretePrototype...")
        return ConcretePrototype(self.rc)

    def onDesc(self):
        print("rc:", self.rc)


class SubclassConcretePrototype(ConcretePrototype):
    def __init__(self, rc, tc):
        ConcretePrototype.__init__(self, rc)
        self.tc = tc

    def set_counter(self, c):
        self.c = c

    def clone(self):
        print("Cloning SubclassConcretePrototype...")
        ret = SubclassConcretePrototype(self.rc, self.tc)
        ret.set_counter(self.c)
        return ret

    def onDesc(self):
        ConcretePrototype.onDesc(self)
        print("tc:", self.tc)
        print("c:", self.c)


class PrototypeRegistry:
    def __init__(self):
        self.items = {}

    def getByKey(self, key):
        if key in self.items:
            return self.items[key]
        else:
            return None

    def setByKey(self, key, item):
        self.items[key] = item


def client():
    pr = PrototypeRegistry()
    c1 = ConcretePrototype(10)
    pr.setByKey(10, c1)
    c2 = SubclassConcretePrototype(11, "tc")
    c2.set_counter("counter")
    pr.setByKey(11, c2)
    cp1 = pr.getByKey(10).clone()
    print("=====cp1=====")
    cp1.onDesc()
    print("c1:", id(c1), " and cp1:", id(cp1))
    cp2 = pr.getByKey(11).clone()
    print("=====cp2=====")
    cp2.onDesc()
    print("c2:", id(c2), " and cp2:", id(cp2))


if __name__ == "__main__":
    client()
