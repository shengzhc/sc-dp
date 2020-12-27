"""

Command Pattern

1. Command Pattern moves biz logic into concrete "Command" obj, it is "analog"
   to a "stateful" action handler case.
2. Command can be pre-configured so the "execute" interface can be generic for all
   possible commands.
3. Whether to 'centralize' commands within executor or not is up to the special case,
   i.e. Command can be a simple data model and the executor can be the one that "produce"
   and "switch" among handlings.
4. Sender/invoker usually is not responsible for creating the cmd, instead cmd is passed in
   and sender/invoker just triggers the cmd.
5. Command in general isn't doing biz logic, but simply pass the "bundled" request info to
   the underlying service.

"""


class ICommand:
	def execute(self):
		pass


class ConcreteCommand(ICommand):
	def __init__(self, receiver):
		self.receiver = receiver

	def execute(self):
		if self.receiver is not None:
			print("ConcreteCommand::execute()")
			self.receiver.do_some_action()
		else:
			raise Exception("non-receiver associated")


class Sender:
	def __init__(self, command):
		self.command = command

	def do_some_action(self):
		if self.command is not None:
			self.command.execute()
		else:
			raise Exception("non-command associated")


class Receiver:
	def do_some_action(self):
		print("Receiver::do_some_action()")


def client():
	rev = Receiver()
	cmd = ConcreteCommand(rev)
	try:
		sender = Sender(None)
		sender.do_some_action()
	except Exception as ex:
		print("Caught exception:", ex)
	
	sender = Sender(cmd)
	sender.do_some_action()


if __name__ == "__main__":
	client()