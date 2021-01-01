#ifndef ADAPTER_DESIGN_PATTERN
#define ADAPTER_DESIGN_PATTERN

#include <iostream>
#include <string>

#include "designpattern.h"

namespace adapter {
	namespace {
		class IService {
		public:
			virtual void doSomeWork(std::string data) = 0;
		};

		class Service : public IService {
		public:
			void doSomeWork(std::string data);
		};

		class Adapter : public IService {
		private:
			IService *service;
		public:
			void doSomeWork(std::string data);
			Adapter(IService *service);
		};
	}

	class AdapterDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
	};
}

#endif