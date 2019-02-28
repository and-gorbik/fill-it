from item import Item
from map import Map
from extimer import extimer

class SolverError(Exception):
    pass

class Solver:
    def __init__(self, filename):
        with open(filename) as f:
            self._items = self._read_items(f)
        if self._items is None:
            raise SolverError("Incorrect input")
        self._map = Map(self._items)
    
    def _read_items(self, f):
        items = []
        symbol = 'A'
        while True:
            src = f.read(20)
            if not src:
                break
            item = Item(src, symbol)
            if item.is_correct():
                items.append(item)
            else:
                return None
            symbol = chr(ord(symbol) + 1)
        return items

    def print_items(self):
        for i in self._items:
            print(i, "\n")

    def response(self):
        print(self._map)

    def run(self):
        with extimer():
            self._map.fill()


if __name__ == '__main__':
    from init import run

    run(filename='data.txt')
    solver = Solver(filename='data.txt')
    solver.print_items()
