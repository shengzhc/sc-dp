#ifndef ABSTRACT_FACTORY_DESIGN_PATTERN
#define ABSTRACT_FACTORY_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace abstractfactory {
	namespace {
		class Chair {
		public:
			virtual void doChair() = 0;
		};

		class Table {
		public:
			virtual void doTable() = 0;
		};

		class AbstractFactory {
		public:
			virtual Chair *createChair() = 0;
			virtual Table *createTable() = 0;
		};

		class WoodChair : public Chair {
		public:
			void doChair() {
				std::cout << "WoodChair::doChair()" << std::endl;
			}
		};

		class SteelChair : public Chair {
		public:
			void doChair() {
				std::cout << "SteelChair::doChair()" << std::endl;
			}
		};

		class WoodTable : public Table {
		public:
			void doTable() {
				std::cout << "WoodTable::doTable()" << std::endl;
			}
		};

		class SteelTable : public Table {
		public:
			void doTable() {
				std::cout << "SteelTable::doTable()" << std::endl;
			}
		};

		class WoodFactory : public AbstractFactory {
		public:
			Chair *createChair();
			Table *createTable();
		};

		class SteelFactory : public AbstractFactory {
		public:
			Chair *createChair();
			Table *createTable();
		};
	}

	class AbstractFactoryDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif