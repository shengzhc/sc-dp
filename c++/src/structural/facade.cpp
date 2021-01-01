#include <iostream>

#include "facade.h"

namespace facade {
	using namespace std;
	void SubsystemA::doSomeWork() {
		cout << "SubsystemA::doSomeWork()..." << endl;
	}

	void SubsystemB::doSomeOtherWork() {
		cout << "SubsystemB::doSomeOtherWork()..." << endl;
	}

	Facade::Facade(SubsystemA *sa, SubsystemB *sb) : sa(sa), sb(sb) {}

	void Facade::execute() {
		cout << "Facade::execute()..." << endl;
		this->sa->doSomeWork();
		this->sb->doSomeOtherWork();
	}

	void FacadeDesignPattern::example() {
		Facade *facade = new Facade((new SubsystemA()), (new SubsystemB()));
		facade->execute();
	}

	std::string FacadeDesignPattern::getName() {
		return "Facade Design Pattern";
	}
}