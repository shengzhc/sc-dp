#ifndef VISITOR_DESIGN_PATTERN
#define VISITOR_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace visitor {
	namespace {
		class Visitor;
		class Element {
		public:
			virtual void accept(Visitor *v) = 0;
		};

		class ConcreteElementA : public Element {
		private:
			void doSomeWork();
		public:
			void accept(Visitor *v);
			friend class Visitor;
		};

		class ConcreteElementB : public Element {
		private:
			void doSomeOtherWork();
		public:
			void accept(Visitor *v);
			friend class Visitor;
		};

		class Visitor {
		public:
			virtual void visitElementA(ConcreteElementA *e);
			virtual void visitElementB(ConcreteElementB *e);
		};
	}

	class VisitorDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif