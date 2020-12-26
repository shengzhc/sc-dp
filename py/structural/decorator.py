"""

Decorator Pattern

1. Wrapper is an alternative term to represent Decorator.
2. Decorator can be 'treated' as a single-directional linked list,
   where step by step 'decoration' is executed.
3. Component can be treated as leaf node, whereas Decorator can be
   'treated' as a container node with extra process.
4. Component doesn't initialize with another compoent, but Decorator
   can be initialized with component or decorator(implements component)

"""


class IComponent:
	def do_some_action(self):
		pass


class ConcreteComponent:
	def do_some_action(self):
		print("ConcreteComponent::do_some_action()")


class BaseDecorator(IComponent):
	def __init__(self, c):
		self.c = c

	def do_some_action(self):
		self.c.do_some_action()


class ConcreteDecoratorA(BaseDecorator):
	def do_some_action(self):
		super().do_some_action()
		print("Extra: ConcreteDecoratorA::do_some_action()")


class ConcreteDecoratorB(BaseDecorator):
	def do_some_action(self):
		super().do_some_action()
		print("Extra: ConcreteDecoratorB::do_some_action()")


def client():
	da = ConcreteDecoratorA(ConcreteComponent())
	db = ConcreteDecoratorB(da)
	db.do_some_action()


if __name__ == "__main__":
	client()