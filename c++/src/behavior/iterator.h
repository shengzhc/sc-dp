#ifndef ITERATOR_DESIGN_PATTERN
#define ITERATOR_DESIGN_PATTERN

#include <iostream>
#include <vector>
#include <unordered_set>

#include "designpattern.h"

namespace dp_iterator {
	namespace {
		class Item {
		private:
			int value;
		public:
			Item(int value) : value(value) {}
			void onDesc() { std::cout << "Item: " << value << std::endl; }
		};

		class Iterator {
		public:
			virtual bool hasMore() = 0;
			virtual Item *getNext() = 0;
		};

		class IteratableCollection {
		public:
			virtual Iterator *createIterator() = 0;
		};

		class ConcreteCollection;

		class ConcreteIterator : public Iterator {
		private:
			ConcreteCollection *collection;
			std::unordered_set<int> visited;
		public:
			ConcreteIterator(ConcreteCollection *collection);
			bool hasMore();
			Item *getNext();
		};

		class ConcreteCollection : public IteratableCollection {
		private:
			std::vector<Item *> items;
		public:
			ConcreteCollection();
			Iterator *createIterator();
			friend class ConcreteIterator;
		};
	}

	class IteratorDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif