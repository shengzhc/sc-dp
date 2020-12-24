"""

Builder Pattern

1. Builder pattern is to solve complexity for step-by-step process.
2. Concrete builder implements different "construction" step and
   specify different product result.
3. Products are not necessarily of common interface, only the builder
   share the same interface of what "construction"-steps are needed.
4. Director role is optional, it defines the "procesure" of instructing
   builder in common, and delegate creating product to builder if products
   are not sharing the same interface.


"""


class ProductA:
    def onDesc(self):
        print("This is productA, no common interface for products")


class ProductB:
    def onDesc(self):
        print("This is productB, no common interface for products")


class IProductBuilder:
    def withCover(self):
        pass

    def withContent(self):
        pass

    def withBrand(self):
        pass


class ConcreteProductBuilderA(IProductBuilder):
    def withCover(self):
        print("A: Building cover...")

    def withContent(self):
        print("A: Building content...")

    def withBrand(self):
        print("A: Building brand...")

    def build(self):
        return ProductA()


class ConcreteProductBuilderB(IProductBuilder):
    def withCover(self):
        print("B: Building cover...")

    def withContent(self):
        print("B: Building content...")

    def withBrand(self):
        print("B: Building brand...")

    def build(self):
        return ProductB()


class Director:
    def makeProduct(self, builder):
        builder.withCover()
        builder.withBrand()
        builder.withContent()


def client():
    builderA = ConcreteProductBuilderA()
    builderB = ConcreteProductBuilderB()
    director = Director()
    director.makeProduct(builderA)
    builderA.build().onDesc()
    director.makeProduct(builderB)
    builderB.build().onDesc()


if __name__ == "__main__":
    client()
