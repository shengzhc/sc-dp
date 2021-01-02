#include <iostream>

#include "memento.h"

namespace memento {
	using namespace std;
	Memento *Originator::save() {
		return new Memento(value + 5);
	}

	void Originator::restore(Memento *m) {
		this->value = m->value - 5;
	}

	void Originator::onDesc() {
		cout << "Originator's current value: " << value << endl;
	}

	void Originator::doSomeWork() {
	 	value ++;
	}

	void CareTaker::save() {
		Memento *const m = this->originator->save();
		this->list.push_back(m);
	}

	void CareTaker::undo() {
		Memento *const m = this->list.back();
		this->list.pop_back();
		this->originator->restore(m);
	}

	void MementoDesignPattern::example() {
		Originator *const o = new Originator();
		CareTaker *const ct = new CareTaker(o);
		o->doSomeWork();
		ct->save();
		cout << "After 1st save:" << endl;
		o->onDesc();
		o->doSomeWork();
		ct->save();
		cout << "After 2nd save:" << endl;
		o->onDesc();
		ct->undo();
		cout << "After 1st undo:" << endl;
		o->onDesc();
		ct->undo();
		cout << "Aftere 2nd undo:" << endl;
		o->onDesc();
	}

	string MementoDesignPattern::getName() {
		return "Memento Design Pattern";
	}

}