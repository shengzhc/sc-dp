#include <iostream>

#include "proxy.h"

namespace proxy {
	using namespace std;
	void Service::execute() {
		cout << "Service::execute()" << endl;
	}

	Proxy::Proxy(IService *service) : service(service) {}

	void Proxy::preprocess() {
		cout << "Proxy::preprocess()..." << endl;
	}

	void Proxy::postprocess() {
		cout << "Proxy::postprocess()...." << endl;
	}

	void Proxy::execute() {
		this->preprocess();
		this->service->execute();
		this->postprocess();
	}

	void ProxyDesignPattern::example() {
		IService *s = new Proxy(new Service());
		s->execute();
	}

	string ProxyDesignPattern::getName() {
		return "Proxy Design Pattern";
	}
}