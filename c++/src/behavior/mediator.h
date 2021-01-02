#ifndef MEDIATOR_DESIGN_PATTERN
#define MEDIATOR_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace mediator {
	namespace {
		class Mediator;
		class Component {
		protected:
			Mediator *m;
		public:
			Component(Mediator *m) : m(m) {}
			virtual void doSomeWork() = 0;
			virtual void askToDoSomeWork() = 0;
		};

		class Mediator {
		private:
			Component *ca;
			Component *cb;
		public:
			void notify(Component *c);
			void setComponentA(Component *ca);
			void setComponentB(Component *cb);
		};

		class ConcreteComponentA : public Component {
		public:
			ConcreteComponentA(Mediator *m);
			void doSomeWork();
			void askToDoSomeWork();
		};

		class ConcreteComponentB : public Component {
		public:
			ConcreteComponentB(Mediator *m);
			void doSomeWork();
			void askToDoSomeWork();
		};
	}

	class MediatorDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif