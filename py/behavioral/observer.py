"""

Observere Pattern

"""


class ISubscriber:
	def on_notify(self, msg):
		pass


class ConcreteSubscriberA(ISubscriber):
	def on_notify(self, msg):
		print("ConcreteSubscriberA gets notified: ", msg)


class ConcreteSubscriberB(ISubscriber):
	def on_notify(self, msg):
		print("ConcreteSubscriberB gets notified: ", msg)


class Publisher:
	def __init__(self):
		self.subscribers = []

	def subscribe(self, subscriber):
		if subscriber not in self.subscribers:
			self.subscribers.append(subscriber)

	def unsubscribe(self, subscriber):
		if subscriber in self.subscribers:
			self.subscribers.remove(subscriber)

	# Dummy public func triggered by client for testing...
	def notify(self, msg):
		for subscriber in self.subscribers:
			subscriber.on_notify(msg)


def client():
	p = Publisher()
	s_a = ConcreteSubscriberA()
	s_b = ConcreteSubscriberB()
	p.subscribe(s_a)
	p.subscribe(s_b)
	p.notify("Having both A & B subscribed")
	p.unsubscribe(s_a)
	p.notify("Having only B subscribed")
	p.unsubscribe(s_b)
	p.notify("A & B have been removed")
	print("A & B should be removed completely")


if __name__ == "__main__":
	client()