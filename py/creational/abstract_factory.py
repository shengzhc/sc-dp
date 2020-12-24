"""

Abstract Factory Pattern

1. AF pattern is "enhanced" from Factory Method pattern by having multiple
   factory methods in its 'factory'
2. In general, it is designed that client only deals with abstract factory
   interface/base class, the higher-level caller(either an env config or
   upper-level adapter) creates the concrete factory.
3. Use-case wise, AF pattern solves issues for product families, i.e. multi
   different product types with different product variant of a single
   product type.

"""


class IProductA:
    def onDesc(self):
        print("This is an interface, shouldn't be initiated")


class IProductB:
    def onDesc(self):
        print("This is an interface, shouldn't be initiated")


class ConcreteProductA1(IProductA):
    def onDesc(self):
        print("This is ConcreteProductA1")


class ConcreteProductA2(IProductA):
    def onDesc(self):
        print("This is ConcreteProductA2")


class ConcreteProductB1(IProductB):
    def onDesc(self):
        print("This is ConcreteProductB1")


class ConcreteProductB2(IProductB):
    def onDesc(self):
        print("This is ConcreteProductB2")


class IAbstractFactory:
    def createProductA(self):
        print("This is an abstract method")

    def createProductB(self):
        print("This is an abstract method")


class ConcreteFactory1(IAbstractFactory):
    def createProductA(self):
        print("ConcreteFactory1 produces productA1")
        return ConcreteProductA1()

    def createProductB(self):
        print("ConcreteFactory1 produces productB1")
        return ConcreteProductB1()


class ConcreteFactory2(IAbstractFactory):
    def createProductA(self):
        print("ConcreteFactory2 produces productA2")
        return ConcreteProductA2()

    def createProductB(self):
        print("ConcreteFactor2 produces productB2")
        return ConcreteProductB2()


def client(factory):
    pa = factory.createProductA()
    pb = factory.createProductB()
    pa.onDesc()
    pb.onDesc()


def Main():
    f1 = ConcreteFactory1()
    f2 = ConcreteFactory2()
    client(f1)
    client(f2)


if __name__ == '__main__':
    Main()
