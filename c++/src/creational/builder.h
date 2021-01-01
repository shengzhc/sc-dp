#ifndef BUILDER_DESIGN_PATTERN
#define BUILDER_DESIGN_PATTERN

#include <iostream>
#include <string>

#include "designpattern.h"

namespace builder {
	using namespace designpattern;
	namespace {
		class Builder {
		protected:
			std::string name;
			float price;
		public:
			virtual Product *getResult() = 0;
			Builder *withPrice(float price) { this->price = price; return this; }
			Builder *withName(std::string name) { this->name = name; return this; }
		};

		class ConcreteBuilderA : public Builder {
		public:
			Product *getResult();
		};

		class ConcreteBuilderB : public Builder {
		public:
			Product *getResult();
		};

		class BuilderProduct : public Product {
		private:
			std::string name;
			float price;
		public:
			BuilderProduct(std::string name, float price) : name(name), price(price) {};
			void doSomeWork() {
				std::cout << "Product[" << name << "]'s price is $" << price << std::endl;
			}
		};
	}

	class BuilderDesignPattern : public DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif
