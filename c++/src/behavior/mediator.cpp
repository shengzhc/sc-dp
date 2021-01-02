#include <iostream>

#include "mediator.h"

namespace mediator {
	using namespace std;
	void Mediator::notify(Component *c) {
		if (c == this->ca) {
			this->cb->askToDoSomeWork();
		} else if (c == this->cb) {
			this->ca->askToDoSomeWork();
		} else {
			cout << "Mediator has no such component" << endl;
		}
	}

	void Mediator::setComponentA(Component *ca) {
		this->ca = ca;
	}

	void Mediator::setComponentB(Component *cb) {
		this->cb = cb;
	}

	ConcreteComponentA::ConcreteComponentA(Mediator *m) : Component(m) {}

	void ConcreteComponentA::doSomeWork() {
		cout << "ConcreteComponentA::doSomeWork()" << endl;
		this->m->notify(this);
	}

	void ConcreteComponentA::askToDoSomeWork() {
		cout << "ConcreteComponentA::askToDoSomeWork()" << endl;
	}

	ConcreteComponentB::ConcreteComponentB(Mediator *m) : Component(m) {}

	void ConcreteComponentB::doSomeWork() {
		cout << "ConcreteComponentB::doSomeWork()" << endl;
		this->m->notify(this);
	}

	void ConcreteComponentB::askToDoSomeWork() {
		cout << "ConcreteComponentB::askToDoSomeWork()" << endl;
	}

	void MediatorDesignPattern::example() {
		Mediator *const m = new Mediator();
		ConcreteComponentA *const ca = new ConcreteComponentA(m);
		ConcreteComponentB *const cb = new ConcreteComponentB(m);
		m->setComponentA(ca);
		m->setComponentB(cb);
		ca->doSomeWork();
		cb->doSomeWork();
	}

	string MediatorDesignPattern::getName() {
		return "Mediator Design Pattern";
	}
}