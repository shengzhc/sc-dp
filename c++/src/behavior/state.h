#ifndef STATE_DESIGN_PATTERN
#define STATE_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace dp_state {
	namespace {
		class Context;
		class State {
		private:
			int value;
			Context *c;
		public:
			State(int value, Context *context) : value(value), c(context) {}
			void doSomeWork();
		};

		class Context {
		private:
			State *state;
		public:
			Context();
			void changeState(State *s);
			void doSomeWork();
		};

	}

	class StateDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif