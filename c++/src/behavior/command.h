#ifndef COMMAND_DESIGN_PATTERN
#define COMMAND_DESIGN_PATTERN

#include <iostream>

#include "designpattern.h"

namespace command {
	namespace {
		class Receiver;

		class Command {
		protected:
			Receiver *receiver;
		public:
			Command(Receiver *r);
			virtual void execute() = 0;
		};

		class StringCommand : public Command {
		private:
			std::string value;
		public:
			StringCommand(std::string value, Receiver *r);
			void execute();
		};

		class NumberCommand : public Command {
		private:
			int value;
		public:
			NumberCommand(int value, Receiver *r);
			void execute();
		};

		class Invoker {
		private:
			Command *cmd;
		public:
			void setCommand(Command *cmd);
			void execute();
		};

		class Receiver {
		public:
			void uppercase(std::string data);
			void square(int data);
		};
	}

	class CommandDesignPattern : public designpattern::DesignPattern {
	public:
		void example();
		std::string getName();
	};
}

#endif