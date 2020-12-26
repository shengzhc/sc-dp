"""

Proxy Pattern

1. Proxy Pattern is "analog" to encapsulated service wrapper with additional process if needed.
2. Introducing the Proxy wrapper helps with caching previous result.
3. XXXCoordinator is another term simliar to Proxy.
4. Caching & lazy initialization are advantages of Proxy Pattern.

"""

class IService:
	def do_some_action(self):
		pass


class Service(IService):
	def do_some_action(self):
		print("Service is taking action...")


class Proxy(IService):
	def __init__(self):
		self.service = None

	def do_some_action(self):
		print("Proxy is pre-processing the request...")
		if self.service is None:
			self.service = Service()
		self.service.do_some_action()
		print("Proxy is post-processing the request...")


def client():
	client_service = Proxy()
	client_service.do_some_action()


if __name__ == "__main__":
	client()