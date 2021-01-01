#include <iostream>

#include "factorymethod.h"
#include "abstractfactory.h"
#include "builder.h"
#include "singleton.h"
#include "adapter.h"

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

	do {
		cout << "Choose the example aboove(Q or q to abort): ";
		char input = ' ';
		cin >> input;
		if (tolower(input) == 'q') break;
		switch ((int)(input - '0')) {
			case 1: {
				DesignPattern *const dp = new factorymethod::FactoryMethodDesignPattern();
				dp->example();
				break;
			}
			case 2: {
				DesignPattern *const dp = new abstractfactory::AbstractFactoryDesignPattern();
				dp->example();
				break;
			}
			case 3: {
				DesignPattern *const dp = new builder::BuilderDesignPattern();
				dp->example();
				break;
			}
			case 4: {
				DesignPattern *const dp = new singleton::SingletonDesignPattern();
				dp->example();
				break;
			}
			case 5: {
				DesignPattern *const dp = new adapter::AdapterDesignPattern();
				dp->example();
				break;
			}

			default:
				cout << "Please enter a number shown above" << endl;
				continue;
		}
	} while (true);
	return 0;
}