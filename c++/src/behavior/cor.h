#ifndef COR_DESIGN_PATTERN
#define COR_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace cor {
	namespace {
		class Responder {
		protected:
			Responder *next;
		public:
			Responder(Responder *next = NULL);
			virtual bool handle(std::string data);
		};

		class LowerResponder : public Responder {
		public:
			LowerResponder(Responder *next = NULL);
			bool handle(std::string data);
		};

		class UpperResponder : public Responder {
		public:
			UpperResponder(Responder *next = NULL);
			bool handle(std::string data);
		};
	}

	class CORDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif