#include <iostream>

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
		switch (input - '0') {
			case 0:
				break;
			case 1:
				break;
			default:
				cout << "Please enter a number shown above" << endl;
				continue;
		}
	} while (true);
	return 0;
}