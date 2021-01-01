#include <iostream>

#include "flyweight.h"

namespace flyweight {
	using namespace std;
	Flyweight::Flyweight(string identifier) : identifier(identifier) {}

	void Flyweight::execute() {
		cout << "Flyweight[" << this->identifier << "] is executing..." << endl;
	}

	Flyweight *FlyweightFactory::getFlyweight(string identifier) {
		if (this->pool.find(identifier) == this->pool.end()) {
			Flyweight *const f = new Flyweight(identifier);
			this->pool.insert({identifier, f});
		}
		return this->pool[identifier];
	}

	void FlyweightDesignPattern::example() {
		FlyweightFactory *const factory = new FlyweightFactory();
		Flyweight *const f1 = factory->getFlyweight("str1");
		f1->execute();
		Flyweight *const f2 = factory->getFlyweight("str2");
		f2->execute();
		Flyweight *const f3 = factory->getFlyweight("str1");
		f3->execute();
	}

	string FlyweightDesignPattern::getName() {
		return "Flyweigt Design Pattern";
	}
}