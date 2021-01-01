#ifndef FACADE_DESIGN_PATTERN
#define FACADE_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace facade {
	namespace {
		class SubsystemA {
		public:
			void doSomeWork();
		};

		class SubsystemB {
		public:
			void doSomeOtherWork();
		};

		class Facade {
		private:
			SubsystemA *sa;
			SubsystemB *sb;
		public:
			Facade(SubsystemA *sa, SubsystemB *sb);
			void execute();
		};
	}

	class FacadeDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif