"""

Memento Pattern

Majorly used to build record:undo/roll-back cases.

1. Originator itself handles the creation of a snapshot and how
   to restore it.
2. Consumer/History-tracker/Caretaker of Memento/Snapshot consumes through an
   simplified interface without much access to internal state of the Memento.
3. Both Originator or Memento can define the restore func. If the later one, it
   simply passes to the Originator to execute restore behavior.


NOTE(shengzhc):
To make Memento encapsulated, the class can be privately defined in Originator,
and Originator class/module only exposes interface out.

"""


class IMemento:
	def __init__(self, originator):
		self.originator = originator

	def restore(self):
		if self.originator is not None:
			self.originator.restore(self)
		else:
			raise Exception("Originator is None unexpectedly")


class ConcreteMemento(IMemento):
	def __init__(self, originator, states):
		super().__init__(originator)
		self.states = states


class Originator:
	def __init__(self):
		self.__counter = 3

	def save(self):
		print("Saving state, before: ", self.__counter, " and after: ", self.__counter + 1)
		states = range(self.__counter)
		self.__counter += 1
		return ConcreteMemento(self, states)

	def restore(self, memento):
		prev = self.__counter
		self.__counter = len(memento.states)
		print("Restoring state, before: ", prev, " and after: ", self.__counter)


def client():
	o = Originator()
	history = []
	history.append(o.save())
	history.append(o.save())
	history.append(o.save())
	for m in history[::-1]:
		m.restore()


if __name__ == "__main__":
	client()