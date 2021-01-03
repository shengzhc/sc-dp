#include <iostream>

#include "templatemethod.h"

namespace templatemethod {
	using namespace std;
	void ConcreteClassA::stepA() {
		cout << "ConcreteClassA::stepA()..." << endl;
	}

	void ConcreteClassB::stepB() {
		cout << "ConcreteClassB::stepB()..." << endl;
	}

	void TemplateMethodDesignPattern::example() {
		ConcreteClassA *const a = new ConcreteClassA();
		a->templateMethod();
		ConcreteClassB *const b = new ConcreteClassB();
		b->templateMethod();
	}

	string TemplateMethodDesignPattern::getName() {
		return "Template Design Pattern";
	}
}