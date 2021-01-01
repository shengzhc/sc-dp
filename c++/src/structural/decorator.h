#ifndef DECORATOR_DESIGN_PATTERN
#define DECORATOR_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace decorator {
	namespace {
		class Component {
		public:
			virtual void execute() = 0;
		};

		class ConcreteComponent : public Component {
		public:
			void execute();
		};

		class Decorator : public Component {
		protected:
			Component *component;
		public:
			Decorator(Component *component);
			virtual void execute() = 0;
		};

		class ConcreteDecoratorA : public Decorator {
		public:
			ConcreteDecoratorA(Component *component);
			void execute();
		};

		class ConcreteDecoratorB : public Decorator {
		public:
			ConcreteDecoratorB(Component *component);
			void execute();
		};
	}

	class DecoratorDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif