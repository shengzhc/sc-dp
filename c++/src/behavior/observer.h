#ifndef OBSERVER_DESIGN_PATTERN
#define OBSERVER_DESIGN_PATTERN

#include <iostream>
#include <vector>

#include "designpattern.h"

namespace observer {
	namespace {
		class Subscriber {
		private:
			std::string identifier;
		public:
			Subscriber(std::string identifier) : identifier(identifier) {}
			void onNotification(int data);
		};

		class Publisher {
		private:
			std::vector<Subscriber *> subscribers;
		public:
			void subscribe(Subscriber *s);
			void unsubscribe(Subscriber *s);
			void pushNotification(int data);
		};
	}

	class ObserverDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif