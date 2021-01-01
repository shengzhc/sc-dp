#ifndef FACTORY_METHOD_DESIGN_PATTERN
#define FACTORY_METHOD_DESIGN_PATTERN

#include <iostream>
#include <string>

#include "designpattern.h"

namespace factorymethod {
	namespace {
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

		class Factory {
		public:
			virtual Product *createProduct() = 0;
		};

		class ConcreteFactoryA : public Factory {
		public:
			Product *createProduct();
		};

		class ConcreteFactoryB : public Factory {
		public:
			Product *createProduct();
		};
	}

	class FactoryMethodDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif