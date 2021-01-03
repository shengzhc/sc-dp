#include <iostream>

#include "visitor.h"

namespace visitor {
	using namespace std;
	void ConcreteElementA::accept(Visitor *v) {
		v->visitElementA(this);
	}

	void ConcreteElementA::doSomeWork() {
		cout << "ConcreteElementA::doSomeWork()..." << endl;
	}

	void ConcreteElementB::doSomeOtherWork() {
		cout << "ConcreteElementB::doSomeOtherWork()..." << endl;
	}

	void ConcreteElementB::accept(Visitor *v) {
		v->visitElementB(this);
	}

	void Visitor::visitElementA(ConcreteElementA *e) {
		e->doSomeWork();
	}

	void Visitor::visitElementB(ConcreteElementB *e) {
		e->doSomeOtherWork();
	}

	void VisitorDesignPattern::example() {
		ConcreteElementA *const ea = new ConcreteElementA();
		ConcreteElementB *const eb = new ConcreteElementB();
		Visitor *const v = new Visitor();
		ea->accept(v);
		eb->accept(v);
	}

	string VisitorDesignPattern::getName() {
		return "Visitor Design Pattern";
	}
}
