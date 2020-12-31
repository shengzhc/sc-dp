#include <iostream>

#include "factorymethod.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Design Pattern Examples..." << endl;
	cout << "1. Creational - Factory Method" << endl;
	
	do {
		cout << "Choose the example aboove(Q or q to abort): " << endl;
		char input = ' ';
		cin >> input;
		if (tolower(input) == 'q') break;
		switch ((int)(input - '0')) {
			case 1: {
				DesignPattern *const dp = new factorymethod::FactoryMethodDesignPattern();
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