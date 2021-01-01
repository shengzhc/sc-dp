#include <iostream>

#include "builder.h"

namespace builder {
	Product *ConcreteBuilderA::getResult() {
		return new BuilderProduct(name, price);
	}

	Product *ConcreteBuilderB::getResult() {
		return new BuilderProduct(name, price * 10);
	}

	void BuilderDesignPattern::example() {
		Builder *b = new ConcreteBuilderA();
		b->withPrice(10)->withName("Product Chair");
		b->getResult()->doSomeWork();
		b = new ConcreteBuilderB();
		b->withPrice(20)->withName("Product Table");
		b->getResult()->doSomeWork();
	}

	std::string BuilderDesignPattern::getName() {
		return "Builder Design Pattern";
	}
}
