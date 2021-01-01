#include <iostream>

#include "designpattern.h"

namespace singleton {
	namespace {
		class Singleton {
		private:
			static Singleton *instance;
			int value;
			Singleton(): value(-1) {}
		public:
			static Singleton *getInstance() {
				if (instance == NULL) {
					instance = new Singleton();
				}
				return instance;
			}
			void setValue(int value) { this->value = value; }
			int getValue() { return this->value; }
		};		
	}

	class SingletonDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
	};
}