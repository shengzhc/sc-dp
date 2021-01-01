#ifndef FLYWEIGHT_DESIGN_PATTERN
#define FLYWEIGHT_DESIGN_PATTERN

#include <iostream>
#include <unordered_map>

#include "designpattern.h"

namespace flyweight {
	namespace {
		class Flyweight {
		private:
			std::string identifier;
		public:
			Flyweight(std::string identifier);
			void execute();
		};

		class FlyweightFactory {
		private:
			std::unordered_map<std::string, Flyweight *> pool;
		public:
			Flyweight *getFlyweight(std::string identifier);
		};
	}

	class FlyweightDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif