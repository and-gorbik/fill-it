from .item import Item
from .map import Map

class Solver:
    def __init__(self, filename, empty, block):
        self._map = Map()
        with open(filename) as f:
            self._items = self._read_items(f, empty, block)
        if self._items is None:
            raise SolverError("Incorrect input")
    
    def _read_items(self, f, ec, bc):
        pass

    def response(self):
        return self._map.print()

    def run(self):
        self._map.fill(self._items)


if __name__ == '__main__':
    pass