#include <iostream>

#include "iterator.h"

namespace dp_iterator {
	using namespace std;
	ConcreteIterator::ConcreteIterator(ConcreteCollection *collection) : collection(collection) {}

	bool ConcreteIterator::hasMore() {
		if (this->collection) {
			return this->collection->items.size() > this->visited.size();
		} else {
			return false;
		}
	}

	Item *ConcreteIterator::getNext() {
		do {
			int idx = rand() % (this->collection->items.size());
			if (this->visited.find(idx) == this->visited.end()) {
				this->visited.insert(idx);
				return this->collection->items[idx];
			}
		} while (true);
	}

	ConcreteCollection::ConcreteCollection() {
		for (int i = 1; i < 10; i++) {
			this->items.push_back(new Item(i));
		}
	}

	Iterator *ConcreteCollection::createIterator() {
		return new ConcreteIterator(this);
	}

	void IteratorDesignPattern::example() {
		ConcreteCollection *const c = new ConcreteCollection();
		Iterator *const iter = c->createIterator();
		while (iter->hasMore()) {
			iter->getNext()->onDesc();
		}
	}

	string IteratorDesignPattern::getName() {
		return "Iterator Design Pattern";
	}
}