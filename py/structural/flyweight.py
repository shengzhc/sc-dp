"""

Flyweight Pattern

1. This is a pattern to split the intrinsic(real properties) and extrinsic states of an obj.
2. Cases like memory over-consumed, the "heavier" instrinsic states will be referenced instead
   of re-allocated each time.
3. Obj holding the intrinsic states is referred as Flyweight and in general they are immutable.
4. Operation to the Flyweight might still take extrinsic states as "inputs", but not stored it
   anywhere in the Flyweight.
5. Flyweight Pattern is mainly to optimize memory pressure for case of tons of large but shared
   data.

"""


class Flyweight:
	def __init__(self, states):
		self.intrinsic_states = states

	def __eq__(self, other):
		if not isinstnace(other, Flyweight):
			raise Error('type mismatch')
		return self.intrinsic_states == states

	def do_some_action(self):
		print("Flyweight[{}][{}]::do_some_action()".format(id(self), self.intrinsic_states))


class FlyweightContainer:
	def __init__(self, flyweight, extrinsic_states):
		self.flyweight = flyweight
		self.extrinsic_states = extrinsic_states

	def do_some_action(self):
		print("FlyweightContainer[{}][{}]::do_some_action()".format(id(self), self.extrinsic_states))
		self.flyweight.do_some_action()


class FlyweightFactory:
	def __init__(self):
		self.flyweights = {}

	def get_flyweight(self, states):
		if states in self.flyweights:
			return self.flyweights[states]

		flyweight = Flyweight(states)
		self.flyweights[states] = flyweight
		return flyweight


def client():
	factory = FlyweightFactory()
	fc1 = FlyweightContainer(factory.get_flyweight("flyweight"), "fc1")
	fc2 = FlyweightContainer(factory.get_flyweight("flyweight"), "fc2")
	fc1.do_some_action()
	fc2.do_some_action()


if __name__ == "__main__":
	client()