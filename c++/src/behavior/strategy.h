#ifndef STRATEGY_DESIGN_PATTERN
#define STRATEGY_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace strategy {
	namespace {
		class Strategy {
		public:
			virtual void doSomeWork() = 0;
		};

		class Context {
		private:
			Strategy *strategy;
		public:
			void setStrategy(Strategy *strategy);
			void doSomeWork();
		};

		class ConcreteStrategyA : public Strategy {
		public:
			void doSomeWork();
		};

		class ConcreteStrategyB : public Strategy {
		public:
			void doSomeWork();
		};
	}

	class StrategyDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif