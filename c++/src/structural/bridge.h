#ifndef BRIDGE_DESIGN_PATTERN
#define BRIDGE_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace bridge {
	namespace {
		class Service {
		public:
			virtual void doInit() = 0;
			virtual void doProcess() = 0;
			virtual void doComplete() = 0;
		};

		// It can be called as Abstraction as application-level PoV.
		class Application {
		private:
			Service *service;
		public:
			Application(Service *service) : service(service) {}
			void doSomeWork();
		};

		class BackService : public Service {
		public:
			void doInit();
			void doProcess();
			void doComplete();
		};
	}

	class BridgeDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif
