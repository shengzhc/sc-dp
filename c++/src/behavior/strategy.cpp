#include <iostream>

#include "strategy.h"

namespace strategy {
	using namespace std;
	void Context::setStrategy(Strategy *strategy) {
		this->strategy = strategy;
	}

	void Context::doSomeWork() {
		this->strategy->doSomeWork();
	}

	void ConcreteStrategyA::doSomeWork() {
		cout << "ConcreteStrategyA::doSomeWork()..." << endl;
	}

	void ConcreteStrategyB::doSomeWork() {
		cout << "ConcreteStrategyB::doSomeWork()..." << endl;
	}

	void StrategyDesignPattern::example() {
		Strategy *const s1 = new ConcreteStrategyA();
		Strategy *const s2 = new ConcreteStrategyB();
		Context *const c = new Context();
		c->setStrategy(s1);
		c->doSomeWork();
		c->setStrategy(s2);
		c->doSomeWork();
	}

	string StrategyDesignPattern::getName() {
		return "Strategy Design Pattern";
	}
}