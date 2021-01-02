#ifndef MEMENTO_DESIGN_PATTERN
#define MEMENTO_DESIGN_PATTERN

#include <iostream>
#include <vector>

#include "designpattern.h"

namespace memento {
	namespace {
		class Originator;
		class Memento {
		private:
			int value;
		public:
			Memento(int value) : value(value) {}
			friend class Originator;
		};

		class Originator {
		private:
			int value;
		public:
			Originator() { value = 10; }
			void doSomeWork();
			Memento *save();
			void restore(Memento *m);
			void onDesc();
		};

		class CareTaker {
		private:
			Originator *originator;
			std::vector<Memento *> list;
		public:
			CareTaker(Originator *originator) : originator(originator) {}
			void save();
			void undo();
		};
	}

	class MementoDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif