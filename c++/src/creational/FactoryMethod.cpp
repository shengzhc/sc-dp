#include <iostream>

namespace factorymethod {
	namespace {
		class Product {
			public:
				virtual void doSomeWork() = 0;
		}

		class ConcreteProductA : Product {
			public:
				void doSomeWork() {
					std::cout << "ConcreteProductA::doSomeWork()" << std::endl;
				}
		}

		class ConcreteProductB: Product {
			public:
				void doSomeWork() {
					std::cout << "ConcreteProductB::doSomeWork()" << std::endl;
				}
		}

		class Factory {
			public:
				virtual Product *createProduct() = 0;
		}

		class ConcreteFactoryA : Factory {
			public:
				Product *createProduct() {
					return new ConcreteProductA();
				}
		}

		class ConcreteFactoryB: Factory {
			public:
				Product *createProduct() {
					return new ConcreteProductB();
				}
		}
	}

	class FactoryMethodDesignPattern : DesignPattern {
		public:
			void example() {
				std::cout << "\n\n\n=======Factory Design Pattern=======" << std::endl;
				Factory *f = new ConcreteFactoryA();
				Product *p = f->createProduct();
				p->doSomeWork();
				f = new ConcreteFactoryB();
				p = f->createProduct();
				p->doSomeWork();
				std::cout << "\n\n\n====================================" << std::endl;
			}
	}
}