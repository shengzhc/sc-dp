#include <iostream>
#include <algorithm>
#include <math.h>

#include "command.h"

namespace command {
	using namespace std;

	Command::Command(Receiver *r) : receiver(r) {}

	StringCommand::StringCommand(string value, Receiver *r) : Command(r), value(value) {}

	void StringCommand::execute() {
		if (this->receiver) {
			this->receiver->uppercase(this->value);
		} else {
			cout << "StringCommand has no receiver" << endl;
		}
	}

	NumberCommand::NumberCommand(int value, Receiver *r) : Command(r), value(value) {}

	void NumberCommand::execute() {
		if (this->receiver) {
			this->receiver->square(this->value);
		} else {
			cout << "StringCommand has no receiver" << endl;
		}
	}

	void Invoker::setCommand(Command *cmd) {
		this->cmd = cmd;
	}

	void Invoker::execute() {
		if (this->cmd) {
			this->cmd->execute();
		} else {
			cout << "Invoker has no Command..." << endl;
		}
	}

	void Receiver::uppercase(string data) {
		cout << "Receiver::uppercase(), before: " << data;
		for_each(data.begin(), data.end(), [](char &c) { c = ::toupper(c); });
		cout << ", after: " << data << endl; 
	}

	void Receiver::square(int data) {
		cout << "Receiver::square(), before: " << data;
		cout << ", after: " << pow(data, 2) << endl; 
	}

	void CommandDesignPattern::example() {
		Receiver *const receiver = new Receiver();
		StringCommand *const stringCommand = new StringCommand("Hello world", receiver);
		NumberCommand *const numberCommand = new NumberCommand(10, receiver);
		Invoker *const invoker = new Invoker();
		invoker->setCommand(stringCommand);
		invoker->execute();
		invoker->setCommand(numberCommand);
		invoker->execute();
	}

	string CommandDesignPattern::getName() {
		return "Command Design Pattern";
	}
}