#include <iostream>

#include "composite.h"

namespace composite {
	using namespace std;
	Component::Component(std::string value) {
		this->value = value;
	}

	Leaf::Leaf(std::string value) : Component(value) {}

	void Leaf::execute() {
		cout << "Leaf[" << this->value << "] is executing..." << endl;
	}

	Branch::Branch(std::string value) : Component(value) {}

	void Branch::execute() {
		cout << "Branch[" << this->value << "] is delegting to children..." << endl;
		for (Component *c : this->children) {
			c->execute();
		}
	}

	void Branch::addComponent(Component *component) {
		this->children.push_back(component);
	}

	void CompositeDesignPattern::example() {
		Branch *branch = new Branch("branch");
		branch->addComponent(new Leaf("leaf_a"));
		branch->addComponent(new Leaf("leaf_b"));
		branch->addComponent(new Leaf("leaf_c"));
		branch->execute();
	}

	std::string CompositeDesignPattern::getName() {
		return "Composite Design Pattern";
	}
}