#include <iostream>

#include "bridge.h"

namespace bridge {
	using namespace std;
	void BackService::doInit() {
		cout << "BackService::doInit()..." << endl;
	}

	void BackService::doProcess() {
		cout << "BackService::doProcess()..." << endl;
	}

	void BackService::doComplete() {
		cout << "BackService::doComplete()..." << endl;
	}

	void Application::doSomeWork() {
		cout << "Application is doing somework" << endl;
		this->service->doInit();
		this->service->doProcess();
		this->service->doComplete();
	}

	void BridgeDesignPattern::example() {
		Service *service = new BackService();
		Application *app = new Application(service);
		app->doSomeWork();
	}

	std::string BridgeDesignPattern::getName() {
		return "Bridge Design Pattern";	
	}
}