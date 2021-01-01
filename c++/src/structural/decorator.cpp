#include <iostream>

#include "decorator.h"

namespace decorator {
	using namespace std;
	void ConcreteComponent::execute() {
		cout << "ConcreteComponent::execute()" << endl;
	}

	Decorator::Decorator(Component *component) : component(component) {}

	ConcreteDecoratorA::ConcreteDecoratorA(Component *componet) : Decorator(componet) {}

	void ConcreteDecoratorA::execute() {
		cout << "ConcreteDecoratorA::execute()" << endl;
		this->component->execute();
	}

	ConcreteDecoratorB::ConcreteDecoratorB(Component *component) : Decorator(component) {}

	void ConcreteDecoratorB::execute() {
		cout << "ConcreteDecoratorB::execute()" << endl;
		this->component->execute();
	}

	void DecoratorDesignPattern::example() {
		Component *c = new ConcreteDecoratorB((new ConcreteDecoratorA(new ConcreteComponent())));
		c->execute();
	}

	std::string DecoratorDesignPattern::getName() {
		return "Decorator Design Pattern";
	}
}