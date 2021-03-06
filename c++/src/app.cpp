#include <iostream>
#include <string>

#include "factorymethod.h"
#include "abstractfactory.h"
#include "builder.h"
#include "singleton.h"
#include "adapter.h"
#include "bridge.h"
#include "composite.h"
#include "decorator.h"
#include "facade.h"
#include "flyweight.h"
#include "proxy.h"
#include "cor.h"
#include "command.h"
#include "iterator.h"
#include "mediator.h"
#include "memento.h"
#include "observer.h"
#include "state.h"
#include "strategy.h"
#include "templatemethod.h"
#include "visitor.h"

int main(int argc, char const *argv[])
{
	using namespace std;
	using namespace designpattern;
	cout << "Design Pattern Examples..." << endl;
	cout << "1. Creational - Factory Method" << endl;
	cout << "2. Creational - Abstract Factory" << endl;
	cout << "3. Creational - Builder" << endl;
	cout << "4. Creational - Singleton" << endl;
	cout << "5. Structual - Adapter" << endl;
	cout << "6. Structual - Bridge" << endl;
	cout << "7. Structual - Composite" << endl;
	cout << "8. Structual - Decorator" << endl;
	cout << "9. Structual - Facade" << endl;
	cout << "10. Structural - Flyweight" << endl;
	cout << "11. Structural - Proxy" << endl;
	cout << "12. Behavior - Chain of Responsibility" << endl;
	cout << "13. Behavior - Command" << endl;
	cout << "14. Behavior - Iterator" << endl;
	cout << "15. Behavior - Mediator" << endl;
	cout << "16. Behavior - Memento" << endl;
	cout << "17. Behavior - Observer" << endl;
	cout << "18. Behavior - State" << endl;
	cout << "19. Behavior - Strategy" << endl;
	cout << "20. Behavior - Template Method" << endl;
	cout << "21. Behavior - Visitor" << endl;

	do {
		cout << "Choose the example above(q to abort): ";
		string input = "";
		cin >> input;
		if (input == "q") break;
		DesignPattern *dp = NULL;
		int i = std::stoi(input);
		switch (i) {
			case 1: {
				dp = new factorymethod::FactoryMethodDesignPattern();
				break;
			}
			case 2: {
				dp = new abstractfactory::AbstractFactoryDesignPattern();
				break;
			}
			case 3: {
				dp = new builder::BuilderDesignPattern();
				break;
			}
			case 4: {
				dp = new singleton::SingletonDesignPattern();
				break;
			}
			case 5: {
				dp = new adapter::AdapterDesignPattern();
				break;
			}
			case 6: {
				dp = new bridge::BridgeDesignPattern();
				break;
			}
			case 7: {
				dp = new composite::CompositeDesignPattern();
				break;
			}
			case 8: {
				dp = new decorator::DecoratorDesignPattern();
				break;
			}
			case 9: {
				dp = new facade::FacadeDesignPattern();
				break;
			}
			case 10: {
				dp = new flyweight::FlyweightDesignPattern();
				break;
			}
			case 11: {
				dp = new proxy::ProxyDesignPattern();
				break;
			}
			case 12: {
				dp = new cor::CORDesignPattern();
				break;
			}
			case 13: {
				dp = new command::CommandDesignPattern();
				break;
			}
			case 14: {
				dp = new dp_iterator::IteratorDesignPattern();
				break;
			}
			case 15: {
				dp = new mediator::MediatorDesignPattern();
				break;
			}
			case 16: {
				dp = new memento::MementoDesignPattern();
				break;
			}
			case 17: {
				dp = new observer::ObserverDesignPattern();
				break;
			}
			case 18: {
				dp = new dp_state::StateDesignPattern();
				break;
			}
			case 19: {
				dp = new strategy::StrategyDesignPattern();
				break;
			}
			case 20: {
				dp = new templatemethod::TemplateMethodDesignPattern();
				break;
			}
			case 21: {
				dp = new visitor::VisitorDesignPattern();
				break;
			}

			default:
				cout << "Please enter a number shown above" << endl;
				continue;
		}
		if (dp != NULL) {
			std::cout << "\n\n=======" << dp->getName() << "=======\n\n" << std::endl;
			dp->example();
			std::cout << "\n\n=======================================\n\n" << std::endl;
		}
	} while (true);
	return 0;
}