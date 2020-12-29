"""

Strategy Pattern

1. Context obj holds a ref to a Strategy, and Strategy is passed from client
   instead of initialized by Context inside.

"""


class IStrategy:
	def do_some_action(self):
		pass


class ConcreteStrategyA(IStrategy):
	def do_some_action(self):
		print("ConcreteStrategyA::do_some_action()")


class ConcreteStrategyB(IStrategy):
	def do_some_action(self):
		print("ConcreteStrategyB::do_some_action()")


class Context:
	def __init__(self, strategy):
		self.strategy = strategy


	def do_some_action(self):
		if self.strategy is not None:
			self.strategy.do_some_action()


def client():
	c = Context(ConcreteStrategyA())
	c.do_some_action()
	c.strategy = ConcreteStrategyB()
	c.do_some_action()


if __name__ == "__main__":
	client()