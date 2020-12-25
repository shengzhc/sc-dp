"""

Adapter Pattern

Allows objects with incompatible interfaces to collaborate,
i.e. convert xml data from external source to json which is
used as core data from a dependent lib used by the app.

1. Adapter is "directly" used by the client through a common
   consuming interface.
2. Adapter can be initialized with a service or dynamically configured
   with a service before it is being consumed.
3. Adapter can also use inheritance instead of interface for class-based
   adapting.

"""


class IClient:
    def perform_first_action(self, type):
        pass

    def perform_second_action(self, type):
        pass


class Service:
    def process(self, data):
        print("Service is processing data...")
        return data.upper()


class Adapter(IClient):
    def __init__(self, service):
        self.service = service

    def perform_first_action(self, type="first"):
        print("Perform first action and converting data...")
        converted_data = type + " action "
        print("Completed first action and produced: ",
              self.service.process(converted_data))

    def perform_second_action(self, type="second"):
        print("Perform second action and converting data...")
        converted_data = type + " action "
        print("Completed second action and produced: ",
              self.service.process(converted_data))


def client():
    adapter = Adapter(Service())
    adapter.perform_first_action()
    print("\n\n\n")
    adapter.perform_second_action()


if __name__ == "__main__":
    client()
