"""

State Pattern

1. It solves blasted State Machine by spliting the state-related
   biz logic into different state classes.
2. States should share a common interface so the "holder/context" doesn't
   need to worry about what state it deals with but just holds a ref
   to state instance.
3. "Holder/Context" provides State a method to allow notify state transition.
4. The main job of "State" objects is to handle the State transition and maybe
   some light-weight process that can be isolated from the "Holder/Context"
   (i.e. logging).

"""


class IState:
	def __init__(self, context):
		self.context = context

	def do_this(self):
		pass

	def do_that(self):
		pass


class ConcreteStateA(IState):
	def do_this(self):
		print("ConcreteStateA::do_this() transites to ConcreteStateB...")
		if self.context is not None:
			self.context.change_state(ConcreteStateB(self.context))
		else:
			raise Exception("self.context should not be None")

	def do_that(self):
		print("ConcreteStateB::do_that() does nothing...")


class ConcreteStateB(IState):
	def do_this(self):
		print("ConcreteStateB::do_this() does nothing...")

	def do_that(self):
		print("ConcreteStateB::do_that() transites to ConcreteStateA...")
		if self.context is not None:
			self.context.change_state(ConcreteStateA(self.context))
		else:
			raise Exception("self.context should not be None")


class Context:
	def __init__(self):
		self.state = ConcreteStateA(self)
	
	def do_this(self):
		if self.state is not None:
			self.state.do_this()
		else:
			raise Exception("self.context should not be None")

	def do_that(self):
		if self.state is not None:
			self.state.do_that()
		else:
			raise Exception("self.context should not be None")

	def change_state(self, state):
		self.state = state


def client():
	c = Context()
	c.do_this()
	c.do_this()
	c.do_that()
	c.do_that()


if __name__ == "__main__":
	client()