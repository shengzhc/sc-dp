"""

Chain of Responsibility Pattern

1. CoR is generally used in case where you have multi-handlers for a single request.
2. CoR can be dynamic-configured and can start anywhere in the 'link-list'.

(shengzhc-only)NOTE:
The direction of the CoR may not be corresponding to how we visualize the responsibility.
Sometimes, it can be a reversed order, i.e. component vs component container, chain may
be built from component to container.

"""


class BaseHandler:
	def __init__(self, next_handler = None):
		self.next_handler =  next_handler

	def set_next_handler(self, next_handler):
		self.next_handler = next_handler

	def execute(self, msg):
		if self.next_handler is not None:
			return self.next_handler.execute(msg)
		return False


class ConcreteHandlerA(BaseHandler):
	def execute(self, msg):
		if msg == 'msg_a':
			print("ConcreteHandlerA is processing msg: ", msg)
			return True
		return super().execute(msg)


class ConcreteHandlerB(BaseHandler):
	def execute(self, msg):
		if msg == 'msg_b':
			print("ConcreteHandlerB is processing msg: ", msg)
			return True
		return super().execute(msg)


def client():
	handler_a = ConcreteHandlerA()
	handler_b = ConcreteHandlerB(handler_a)
	print("Handle `msg_a` {}".format("success" if handler_b.execute('msg_a') else "failed"))
	print("Handle `msg_b` {}".format("success" if handler_b.execute('msg_b') else "failed"))
	print("Handle `msg_c` {}".format("success" if handler_b.execute('msg_c') else "failed"))


if __name__ == "__main__":
	client()
