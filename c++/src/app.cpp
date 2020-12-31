#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Design Pattern Examples..." << endl;
	cout << "1. Creational - Factory Method" << endl;
	cout << "Choose the example aboove(Q or q to abort): " << endl;
	
	char input = ' ';
	cin >> input;
	while (tolower(input) != 'q') {
		int _case = input - '0';
		switch (_case) {
			case 0:
				break;
			case 1:
				break;
			default:
				cout << "Please enter a number shown above" << endl;
				continue;
		}

	}

	return 0;
}