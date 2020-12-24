"""
Factory Method Pattern

1. FM pattern is to separate the responsibility of product and creator
2. Interface/base class impl is the core to open/close principle
3. "Creator" may not be equalvant to what to be intepreted, and the "core"
   of "Creator" is to define abstract createProduct and "close-to" FINAL func
   which is the same across all sub-creators, i.e. the Creator::run in this
   example.
   One example of "Creator" can be a Dialog which has createButton as producer
   to be overridden by sub-creators, and Dialog has an render() func to which
   is the same for a WindowsDialog or a MacDialog.

"""


class Product:
    # @abstract method
    def operate():
        print("Product::operate() ==> abstract method, "
              "should never be called")


class ConcreteProduct1(Product):
    def operate():
        print("ConcreteProduct1::operate()")


class ConcreteProduct2(Product):
    def operate():
        print("ConcreteProduct2::operate()")


class Creator:
    # @abstract method
    def createProduct():
        print("Creator::createProduct() ==> abstract method, "
              "should never be called")

    def run(self):
        """Final func for all concrete creators which share
           the same run function benefiting reusable code snippet"""
        p = self.createProduct()
        print("Creator::run() and produce product:", type(p))


class ConcreteCreator1(Creator):
    def createProduct(self):
        print("ConcreteCreator1::createProduct()")
        return ConcreteProduct1()


class ConcreteCreator2(Creator):
    def createProduct(self):
        print("ConcreteCreator2::createProduct()")
        return ConcreteProduct2()


def Main():
    ConcreteCreator1().run()
    ConcreteCreator2().run()


if __name__ == '__main__':
    Main()
