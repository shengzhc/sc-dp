#include <iostream>
#include <string>
#include <algorithm>

#include "adapter.h"

namespace adapter {
	using namespace std;
	void Service::doSomeWork(std::string data) {
		std::for_each(data.begin(), data.end(), [](char &c) {
			c = ::toupper(c);
		});
		cout << "Service::doSomeWork is converting data to upper-case and result is: " << data << endl;
	}

	void Adapter::doSomeWork(std::string data) {
		cout << "Adapter::doSomeWork is adding 1 to each char, before: " << data << endl;
		std::for_each(data.begin(), data.end(), [](char &c) {
			c += 1;
		});
		cout << "Adapter::doSomeWork is adding 1 to each char, after: " << data << endl;
		this->service->doSomeWork(data);
	}

	void AdapterDesignPattern::example() {
		std::cout << "\n\n\n=======Adapter Design Pattern=======\n" << std::endl;
		string data = "Hello World";
		IService *const service = new Service();
		IService *const adapter = new Adapter(service);
		adapter->doSomeWork(data);
		std::cout << "\n=======================================" << std::endl;
	}
}
