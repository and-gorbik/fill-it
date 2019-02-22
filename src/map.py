from item import Item

class MapContainer:
    """ хранит объекты, размещенные на поле """

    def __init__(self, items: list):
        self._placed_items = []
        self._items = items[::-1]

    def __str__(self):
        return "\n".join([str(i) for i in self._placed_items])

    def push(self):
        """ добавляет элемент в placed_items, удаляя его из items """
        if self.is_full():
            return None
        item = self._items.pop()
        self._placed_items.append(item)
        return item

    def pop(self):
        """ удаляет элемент из placed_items, добавляя его в items """
        if self.is_empty():
            return None
        item = self._placed_items.pop()
        self._items.append(item)
        return item

    def next(self):
        """ возвращает первый элемент в items """
        return self._items[-1] if len(self._items) else None

    def is_full(self):
        return len(self._items) == 0

    def is_empty(self):
        return len(self._placed_items) == 0


class Map:
    def __init__(self, items, size=2):
        self._resize_map(size)
        self._curi, self._curj = 0, 0
        self._container = MapContainer(items)

    def __str__(self):
        return "\n".join(["".join(line) for line in self._data])

    def fill(self):
        while not self._container.is_full(): # пока не размещены все элементы на поле
            while self._curi < self.size:
                if self._check_position():
                    self._place_item()
                elif not self._container.is_empty():
                    self._remove_item()
                self._next_position()
            self._resize_map(self.size + 1)
            self._curi, self._curj = 0, 0

    def _resize_map(self, size):
        self.size = size
        self._data = [['.'] * size] * size

    def _next_position(self):
        if self._curj + 1 < self.size:
            self._curj += 1
        else:
            self._curi += 1
            self._curj = 0

    def _check_position(self):
        for i, j in self._container.next().points:
            if (i + self._curi >= self.size) or (j + self._curj >= self.size):
                return False
            if self._data[i + self._curi][j + self._curj] not in '.':
                return False
        return True

    def _place_item(self):
        item = self._container.push()
        for i, j in item.points:
            self._data[i + self._curi][j + self._curj] = item.chr

    def _remove_item(self):
        item = self._container.pop()
        self._curi, self._curj = item.get_position()
        item.set_position(0, 0)
        for i, j in item.points:
            i, j = item.get_position()
            self._data[i][j] = '.'


if __name__ == '__main__':
    A = "#...\n#...\n#...\n#...\n"
    B = "#...\n##..\n.#..\n....\n"
    C = "##..\n##..\n....\n....\n"
    D = "#...\n###.\n....\n....\n"
    a = Item(A, 'A')
    b = Item(B, 'B')
    c = Item(C, 'C')
    d = Item(D, 'D')
    m = Map([a, b, c, d])
    m.fill()
    m.print()
