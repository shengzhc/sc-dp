#pragma once

#include <iostream>

namespace designpattern {
	class DesignPattern {
	public:
		// Subclass to override to provide examples.
		virtual void example() {
			std::cout << "Subclass to implement example for design pattern" << std::endl;
		}
	};

	class Product {
	public:
		virtual void doSomeWork() = 0;
	};

	class ConcreteProductA : public Product {
	public:
		void doSomeWork() {
			std::cout << "ConcreteProductA::doSomeWork()" << std::endl;	
		}
	};

	class ConcreteProductB : public Product {
	public:
		void doSomeWork() {
			std::cout << "ConcreteProductB::doSomeWork()" << std::endl;
		}
	};
}
