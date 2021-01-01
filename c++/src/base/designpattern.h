#pragma once

#include <iostream>
#include <string>

namespace designpattern {
	class DesignPattern {
	public:
		// Subclass to override to provide examples.
		virtual void example() {
			std::cout << "Subclass to implement example for design pattern" << std::endl;
		}

		virtual std::string getName() = 0;
	};
}
