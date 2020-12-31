#include <iostream>

#include "factorymethod.h"
#include "abstractfactory.h"

int main(int argc, char const *argv[])
{
	using namespace std;
	using namespace designpattern;
	cout << "Design Pattern Examples..." << endl;
	cout << "1. Creational - Factory Method" << endl;
	cout << "2. Creational - Abstract Factory" << endl;

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
			default:
				cout << "Please enter a number shown above" << endl;
				continue;
		}
	} while (true);
	return 0;
}