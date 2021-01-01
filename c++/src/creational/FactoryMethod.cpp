#include <iostream>
#include <string>

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
