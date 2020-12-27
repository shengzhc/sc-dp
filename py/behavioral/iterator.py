"""

Iterator Pattern

It acts as a generic and blurry interaction with collection. Each
iterator class can define its own traversal approach.

1. Iterator most of time is generated by the collection, but it can 
   also be created by client.

"""


class IIterator:
	def __init__(self, collection):
		self.collection = collection

	def get_next(self):
		pass

	def has_more(self):
		pass


class ConcreteIterator(IIterator):
	def __init__(self, collection):
		super().__init__(collection)
		self.current_pos = -1

	def has_more(self):
		length = len(self.collection)
		if length == 0 or self.current_pos >= length - 1:
			return False
		return True

	def get_next(self):
		if not self.has_more():
			return None
		self.current_pos += 1
		return self.collection[self.current_pos]


class IIterableCollection:
	def create_iterator(self):
		pass


class ConcreteCollection(IIterableCollection):
	def __init__(self, list):
		self.list = list

	def create_iterator(self):
		return ConcreteIterator(self.list)


def client():
	c = ConcreteCollection([1,2,3,4,5])
	iterator = c.create_iterator()
	while(iterator.has_more()):
		print(iterator.get_next())
	else:
		print("finish iterating the collection")



if __name__ == "__main__":
	client()