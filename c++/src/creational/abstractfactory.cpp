#include <iostream>
#include <string>

#include "abstractfactory.h"

namespace abstractfactory {
	Chair *WoodFactory::createChair() {
		return new WoodChair();
	}

	Table *WoodFactory::createTable() {
		return new WoodTable();
	}

	Chair *SteelFactory::createChair() {
		return new SteelChair();
	}

	Table *SteelFactory::createTable() {
		return new SteelTable();
	}

	void AbstractFactoryDesignPattern::example() {
		std::cout << "\nWood Factory: " << std::endl;
		AbstractFactory *f = new WoodFactory();
		f->createChair()->doChair();
		f->createTable()->doTable();
		std::cout << "\nSteel Factory: " << std::endl;
		f = new SteelFactory();
		f->createChair()->doChair();
		f->createTable()->doTable();
	}

	std::string AbstractFactoryDesignPattern::getName() {
		return "Abstract Factory Design Pattern";
	}
}