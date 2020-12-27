"""

Mediator Pattern

One of the common-seen cases is MVC architecture, where C performs
the Mediator role to make V independent and flexible.

1. Mediator usually manages all the components and their lifecycles.
2. Mediator can (optionally) define a common interface to allow component
   to send notifications, or just flatten all the notifications into different
   methods.

"""


class IMediator:
	def notify(self, sender, event):
		pass


class ComponentA:
	def __init__(self, mediator):
		self.mediator = mediator

	def onEvent(self):
		if self.mediator is not None:
			self.mediator.notify(self, "ComponentA")


class ComponentB:
	def __init__(self, mediator):
		self.mediator = mediator

	def onEvent(self):
		if self.mediator is not None:
			self.mediator.notify(self, "ComponentB")


class ComponentC:
	def __init__(self, mediator):
		self.mediator = mediator

	def onEvent(self):
		if self.mediator is not None:
			self.mediator.notify(self, "ComponentC")


class ConcreteMediator(IMediator):
	def __init__(self):
		self.component_a = ComponentA(self)
		self.component_b = ComponentB(self)
		self.component_c = ComponentC(self)

	def notify(self, sender, event):
		if sender == self.component_a:
			print("Notification from ComponentA: ", event)
		elif sender == self.component_b:
			print("Notification from ComponentA: ", event)
		elif sender == self.component_c:
			print("Notification from ComponentA: ", event)
		else:
			raise Exception("Un-recognized sender: ", sender)


def client():
	m = ConcreteMediator()
	m.component_a.onEvent()
	m.component_b.onEvent()
	m.component_c.onEvent()


if __name__ == "__main__":
	client()