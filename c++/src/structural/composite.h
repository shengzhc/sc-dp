#ifndef COMPOSITE_DESIGN_PATTERN
#define COMPOSITE_DESIGN_PATTERN

#include <iostream>
#include <vector>

#include "designpattern.h"

namespace composite {
	namespace {
		class Component {
		protected:
			std::string value;
		public:
			Component(std::string value);
			virtual void execute() = 0;
		};

		class Leaf : public Component {
		public:
			Leaf(std::string value);
			void execute();
		};

		class Branch : public Component {
		private:
			std::vector<Component *> children;
		public:
			Branch(std::string value);
			void execute();
			void addComponent(Component *component);
		};

	}

	class CompositeDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif