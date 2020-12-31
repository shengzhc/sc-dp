#include <iostream>

#include "factorymethod.h"

namespace factorymethod {
	using namespace designpattern;
	Product *ConcreteFactoryA::createProduct() {
		return new ConcreteProductA();
	}

	Product *ConcreteFactoryB::createProduct() {
		return new ConcreteProductB();
	}

	void FactoryMethodDesignPattern::example() {
		std::cout << "\n\n\n=======Factory Design Pattern=======\n" << std::endl;
		Factory *f = new ConcreteFactoryA();
		Product *p = f->createProduct();
		p->doSomeWork();
		f = new ConcreteFactoryB();
		p = f->createProduct();
		p->doSomeWork();
		std::cout << "\n=======================================" << std::endl;
	}
}
