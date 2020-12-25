"""

Singletone Pattern

"""

from threading import Lock, Thread


class SingletonMeta(type):
    _instances = {}
    _lock = Lock()
 
    def __call__(cls, *args, **kwargs):
        print(cls, cls._instances)
        with cls._lock:
            if cls not in cls._instances:
                instance = super().__call__(*args, **kwargs)
                cls._instances[cls] = instance
        return cls._instances[cls]


class Singleton1(metaclass=SingletonMeta):
    def __init__(self, value):
        self.value = value

    def some_biz_logic(self):
        pass


class Singleton2(metaclass=SingletonMeta):
    def __init__(self, value):
        self.value = value


def test_singleton(value):
    singleton1 = Singleton1(value)
    singleton2 = Singleton2(value+"2")
    print(singleton1.value)
    print(singleton2.value)


if __name__ == "__main__":
    p1 = Thread(target=test_singleton, args=("FOO",))
    p2 = Thread(target=test_singleton, args=("BAR",))
    p1.start()
    p2.start()
