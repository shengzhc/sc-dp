#include <iostream>

#include "singleton.h"

namespace singleton {
	void SingletonDesignPattern::example() {
		Singleton *const s1 = Singleton::getInstance();
		Singleton *const s2 = Singleton::getInstance();
		std::cout << "s1.value = " << s1->getValue() << ", s2.value = " << s2->getValue() << std::endl;
		s1->setValue(10);
		std::cout << "set s1.value = 10 and get s1.value = " << s1->getValue() << ", s2.value = " << s2->getValue() << std::endl;
	}

	std::string SingletonDesignPattern::getName() {
		return "Singleton Design Pattern";
	}

}