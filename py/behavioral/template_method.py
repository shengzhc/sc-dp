"""

Template Method Pattern

1. Template Method Pattern uses inheritance to allow subclasses to override
   some steps while the "logicial/template" step orders are "finally" defined in the base
   class.
2. (Optionally)Depend on the use-case, "hooks" will be added to the process structure
   to allow subclasses to take some extra actions.

"""

class AbstractClass:
	def do_step_a(self):
		print("Default step a....")

	def do_step_b(self):
		print("Default step b....")

	def do_step_c(self):
		print("Default step c....")

	def template_method(self):
		self.do_step_a()
		self.do_step_b()
		self.do_step_c()


class ConcreteClassA(AbstractClass):
	def do_step_a(self):
		print("ConcreteClassA step a....")


class ConcreteClassB(AbstractClass):
	def do_step_b(self):
		print("ConcreteClassB step b....")


def client():
	ConcreteClassA().template_method()
	ConcreteClassB().template_method()


if __name__ == "__main__":
	client()