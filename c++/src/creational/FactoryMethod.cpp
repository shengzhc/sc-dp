#include <iostream>
#include <string>

#include "factorymethod.h"

namespace factorymethod {
	Product *ConcreteFactoryA::createProduct() {
		return new ConcreteProductA();
	}

	Product *ConcreteFactoryB::createProduct() {
		return new ConcreteProductB();
	}

	void FactoryMethodDesignPattern::example() {
		Factory *f = new ConcreteFactoryA();
		Product *p = f->createProduct();
		p->doSomeWork();
		f = new ConcreteFactoryB();
		p = f->createProduct();
		p->doSomeWork();
	}

	std::string FactoryMethodDesignPattern::getName() {
		return "Factory Design Pattern";
	}
}
