#include <iostream>
#include <string>

#include "factorymethod.h"
#include "abstractfactory.h"
#include "builder.h"
#include "singleton.h"
#include "adapter.h"
#include "bridge.h"

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

	do {
		cout << "Choose the example aboove(Q or q to abort): ";
		char input = ' ';
		cin >> input;
		if (tolower(input) == 'q') break;
		DesignPattern *dp = NULL;
		switch ((int)(input - '0')) {
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

			default:
				cout << "Please enter a number shown above" << endl;
				continue;
		}
		if (dp != NULL) {
			std::cout << "\n\n\n=======" << dp->getName() << "=======\n" << std::endl;
			dp->example();
			std::cout << "\n=======================================" << std::endl;
		}
	} while (true);
	return 0;
}