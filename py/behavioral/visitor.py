"""

Visitor Pattern

1. Visitor Pattern allows Visitee to choose what method in the Visitor to take.

"""


class IVisitor:
	def visit_element_a(self, element):
		pass

	def visit_element_b(self, element):
		pass


class ConcreteVisitor(IVisitor):
	def visit_element_a(self, element):
		print("Visiting ConcreteElementA...")
		print(element.onDescA())

	def visit_element_b(self, element):
		print("Visiting ConcreteElementB...")
		print(element.onDescB())


class IElement:
	def accept(self, visitor):
		pass


class ConcreteElementA(IElement):
	def accept(self, visitor):
		if visitor is not None:
			visitor.visit_element_a(self)
		else:
			raise Exception("Visitor is None")

	def onDescA(self):
		return "I am element A...."


class ConcreteElementB(IElement):
	def accept(self, visitor):
		if visitor is not None:
			visitor.visit_element_b(self)
		else:
			raise Exception("Visitor is None")

	def onDescB(self):
		return "I am element B..."


def client():
	visitor = ConcreteVisitor()
	l = [ConcreteElementA(), ConcreteElementB()]
	for e in l:
		e.accept(visitor)


if __name__ == "__main__":
	client()