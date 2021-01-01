#include <iostream>
#include <string>

#include "factorymethod.h"
#include "abstractfactory.h"
#include "builder.h"
#include "singleton.h"
#include "adapter.h"
#include "bridge.h"
#include "composite.h"
#include "decorator.h"
#include "facade.h"
#include "flyweight.h"

int main(int argc, char const *argv[])
{
	using namespace std;
	using namespace designpattern;
	cout << "Design Pattern Examples..." << endl;
	cout << "1. Creational - Factory Method" << endl;
	cout << "2. Creational - Abstract Factory" << endl;
	cout << "3. Creational - Builder" << endl;
	cout << "4. Creational - Singleton" << endl;
	cout << "5. Structual - Adapter" << endl;
	cout << "6. Structual - Bridge" << endl;
	cout << "7. Structual - Composite" << endl;
	cout << "8. Structual - Decorator" << endl;
	cout << "9. Structual - Facade" << endl;
	cout << "10. Structural - Flyweight" << endl;

	do {
		cout << "Choose the example aboove(q to abort): ";
		string input = "";
		cin >> input;
		if (input == "q") break;
		DesignPattern *dp = NULL;
		int i = std::stoi(input);
		switch (i) {
			case 1: {
				dp = new factorymethod::FactoryMethodDesignPattern();
				break;
			}
			case 2: {
				dp = new abstractfactory::AbstractFactoryDesignPattern();
				break;
			}
			case 3: {
				dp = new builder::BuilderDesignPattern();
				break;
			}
			case 4: {
				dp = new singleton::SingletonDesignPattern();
				break;
			}
			case 5: {
				dp = new adapter::AdapterDesignPattern();
				break;
			}
			case 6: {
				dp = new bridge::BridgeDesignPattern();
				break;
			}
			case 7: {
				dp = new composite::CompositeDesignPattern();
				break;
			}
			case 8: {
				dp = new decorator::DecoratorDesignPattern();
				break;
			}
			case 9: {
				dp = new facade::FacadeDesignPattern();
				break;
			}
			case 10: {
				dp = new flyweight::FlyweightDesignPattern();
				break;
			}

			default:
				cout << "Please enter a number shown above" << endl;
				continue;
		}
		if (dp != NULL) {
			std::cout << "\n\n=======" << dp->getName() << "=======\n\n" << std::endl;
			dp->example();
			std::cout << "\n\n=======================================\n\n" << std::endl;
		}
	} while (true);
	return 0;
}