from .item import Item

class Map:
    def __init__(self, size=2):
        self.size = size
        self._data = [['.'] * size] * size
        self._curi, self.curj = 0, 0
        self._placed_items = []

    def print(self):
        for line in self._data:
            print("".join(line))

    def _moved_item(self, item: Item, i, j):
        new_item = item
        for pair in new_item.points:
            pair[0] += i
            pair[1] += j
        return new_item

    # def _remove_prev_item(self):


    def _add_item(self, item: Item):
        i, j = self._curi, self._curj
        while i < self.size:
            new_item = self._moved_item(item, i, j)
            if self._check_points(new_item):
                self._placed_items.append((item.points, i, j))

    def fill(self, items):
        pass

if __name__ == '__main__':
    m = Map()
    m.print()
    