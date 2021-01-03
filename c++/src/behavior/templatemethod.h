#ifndef TEMPLATE_METHOD_DESIGN_PATTERN
#define TEMPLATE_METHOD_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace templatemethod {
	namespace {
		class AbstractClass {
		public:
			virtual void stepA() { std::cout << "AbstractClass::stepA()..." << std::endl; }
			virtual void stepB() { std::cout << "AbstractClass::stepB()..." << std::endl; }
			virtual void templateMethod() final {
				std::cout << "AbstractClass::templateMethod()..." << std::endl;
				this->stepA();
				this->stepB();
			}
		};

		class ConcreteClassA : public AbstractClass {
		public:
			void stepA();
		};

		class ConcreteClassB : public AbstractClass {
		public:
			void stepB();
		};
	}

	class TemplateMethodDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif