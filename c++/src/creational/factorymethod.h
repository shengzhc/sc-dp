#ifndef FACTORY_METHOD_DESIGN_PATTERN
#define FACTORY_METHOD_DESIGN_PATTERN

#include <iostream>
#include <string>

#include "designpattern.h"

namespace factorymethod {
	namespace {
		class Factory {
		public:
			virtual designpattern::Product *createProduct() = 0;
		};

		class ConcreteFactoryA : public Factory {
		public:
			designpattern::Product *createProduct();
		};

		class ConcreteFactoryB : public Factory {
		public:
			designpattern::Product *createProduct();
		};
	}

	class FactoryMethodDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif