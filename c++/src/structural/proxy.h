#ifndef PROXY_DESIGN_PATTERN
#define PROXY_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace proxy {
	namespace {
		class IService {
		public:
			virtual void execute() = 0;
		};

		class Service : public IService {
		public:
			void execute();
		};

		class Proxy : public IService {
		private:
			IService *service;
			void preprocess();
			void postprocess();
		public:
			Proxy(IService *service);
			void execute();
		};
	}

	class ProxyDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif