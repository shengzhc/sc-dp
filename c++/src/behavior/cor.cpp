#include <iostream>

#include "cor.h"

namespace cor {
	using namespace std;
	Responder::Responder(Responder *next) : next(next) {}

	bool Responder::handle(string data) {
		if (this->next) {
			return this->next->handle(data);
		}
		cout << "Unable to handle data: " << data << endl;
		return false;
	}

	LowerResponder::LowerResponder(Responder *next) : Responder(next) {}

	bool LowerResponder::handle(string data) {
		if (data.length() <= 0) {
			return false;
		}

		if (data[0] >= 'a' && data[0] <= 'n') {
			cout << "LowerResponder handles the data: " << data << endl;
			return true;
		} else {
			return Responder::handle(data);
		}
	}

	UpperResponder::UpperResponder(Responder *next) : Responder(next) {}

	bool UpperResponder::handle(string data) {
		if (data.length() <= 0) {
			return false;
		}

		if (data[0] >= 'o' && data[0] <= 'z') {
			cout << "UpperResponder handles the data: " << data << endl;
			return true;
		} else {
			return Responder::handle(data);
		}
	}

	void CORDesignPattern::example() {
		LowerResponder *const resp = new LowerResponder(new UpperResponder());
		resp->handle("hello world");
		resp->handle("zibra");
		resp->handle("What's up");
	}

	string CORDesignPattern::getName() {
		return "Chain of Responsibility Design Pattern";
	}
}