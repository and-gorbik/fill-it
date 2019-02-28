from .item import Item
from .map import Map

class SolverError(Exception):
    pass

class Solver:
    def __init__(self, filename, empty, block):
        with open(filename) as f:
            self._items = self._read_items(f, empty, block)
        if self._items is None:
            raise SolverError("Incorrect input")
        self._map = Map(self._items)
    
    def _read_items(self, f, ec, bc):
        # чтение из файла
        # None, если ошибка при чтении
        # возвращает список элементов

    def response(self):
        print(self._map)

    def run(self):
        self._map.fill()


if __name__ == '__main__':
    pass