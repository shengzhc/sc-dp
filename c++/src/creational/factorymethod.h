#ifndef FACTORY_METHOD_DESIGN_PATTERN
#define FACTORY_METHOD_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace factorymethod {
	namespace {
		class Product {
		public:
			virtual void doSomeWork() = 0;
		};

		class ConcreteProductA : public Product {
		public:
			void doSomeWork();
		};

		class ConcreteProductB : public Product {
		public:
			void doSomeWork();
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

	class FactoryMethodDesignPattern : public DesignPattern {
	public:
		void example();
	};
}

#endif