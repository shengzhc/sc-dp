#include <iostream>

#include "observer.h"

namespace observer {
	using namespace std;
	void Subscriber::onNotification(int data) {
		cout << "Subscriber[" << identifier << "]::onNotification: " << data << endl;
	}

	void Publisher::subscribe(Subscriber *s) {
		if (find(subscribers.begin(), subscribers.end(), s) == subscribers.end()) {
			subscribers.push_back(s);
		}
	}

	void Publisher::unsubscribe(Subscriber *s) {
		const auto iter = find(subscribers.begin(), subscribers.end(), s);
		if (iter != subscribers.end()) {
			subscribers.erase(iter);
		}
	}

	void Publisher::pushNotification(int data) {
		for (Subscriber *s : subscribers) {
			s->onNotification(data);
		}
	}

	void ObserverDesignPattern::example() {
		Publisher *const p = new Publisher();
		p->subscribe(new Subscriber("s1"));
		p->subscribe(new Subscriber("s2"));
		p->pushNotification(10);		
	}

	string ObserverDesignPattern::getName() {
		return "Observer Design Pattern";
	}
}