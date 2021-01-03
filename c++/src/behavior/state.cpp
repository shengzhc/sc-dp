#include <iostream>

#include "state.h"

namespace dp_state {
	using namespace std;

	void State::doSomeWork() {
		cout << "State[" << value << "]::doSomeWork()..." << endl;
		this->c->changeState(new State(value+1, this->c));
	}

	Context::Context() {
		this->state = new State(1, this);
	}

	void Context::changeState(State *s) {
		state = s;
	}

	void Context::doSomeWork() {
		cout << "Context::doSomeWork()..." << endl;
		this->state->doSomeWork();
	}

	void StateDesignPattern::example() {
		Context *const c = new Context();
		for (int i = 0; i < 5; i++) {
			c->doSomeWork();
		}
	}

	string StateDesignPattern::getName() {
		return "State Design Pattern";
	}
}