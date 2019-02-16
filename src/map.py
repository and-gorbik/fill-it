from item import Item

class MapContainer:
    """ хранит объекты, размещенные на поле """
    def __init__(self, items: list):
        self._placed_items = []
        self._items = items[::-1]

    def push(self):
        """ добавляет элемент в placed_items, удаляя его из items """
        item = self._items.pop()
        self._placed_items.append(item)
        return item

    def pop(self):
        """ удаляет элемент из placed_items, добавляя его в items """
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
        while not self._container.is_full():
            while self._next_position():
                if self._check_position():
                    self._place_item()
                elif not self._container.is_empty():
                    self._remove_item()
            self._resize_map(self.size + 1)
            self._curi, self._curj = 0, 0

    def _resize_map(self, size):
        self.size = size
        self._data = [['.'] * size] * size

    def _next_position(self):
        if self._curj + 1 < self.size:
            self._curj += 1
            return True
        if self._curi + 1 < self.size:
            self._curi += 1
            self._curj = 0
            return True
        return False

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


"""
class Map:
    def __init__(self, size=2):
        self._resize_map(size)
        self._curi, self._curj = 0, 0
        self._placed_items = []

    def __str__(self):
        return "\n".join(["".join(line) for line in self._data])

    def _resize_map(self, size):
        self.size = size
        self._data = [['.'] * size] * size

    def _check_points(self, item, di, dj):
        for i, j in item.points:
            if (i + di >= self.size) or (j + dj >= self.size):
                return False
            if self._data[i + di][j + dj] not in '.':
                return False
        return True

    def _add_item(self, item):
        for di in range(self._curi, self.size):
            for dj in range(self._curj, self.size):
                if self._check_points(item, di, dj):
                    item.posi, item.posj = di, dj
                    self._placed_items.append(item)
                    for i, j in item.points:
                        self._data[i + di][j + dj] = item.chr
                    return True
        return False

    def _remove_prev_item(self):
        item = self._placed_items.pop()
        for i, j in item.points:
            self._data[i + item.posi][j + item.posj] = '.'
        return item

    def _move_position(self):
        if j + 1 < self.size:
            self._curj += 1
            return True
        if i + 1 < self.size:
            self._curi += 1
            self._curj = 0
            return True
        return False

    def fill(self, figures):
        while len(figures):
            # print("Stack size: {} - CurI: {} - CurJ: {}".format(len(figures), self._curi, self._curj))
            if self._add_item(figures[0]):
                self._curi, self._curj = figures[0].posi, figures[0].posj
                figures.pop(0)
                print(self, "\n")
            # elif size == len(figures):
            #     self._resize_map(self.size + 1)
            #     self._curi, self._curj = 0, 0
            else:
                if len(self._placed_items) != 0: # если есть хотя бы один размещенный элемент
                    item = self._remove_prev_item()
                    self._curi, self._curj = item.posi, item.posj
                    item.posi, item.posj = 0, 0
                    figures.insert(0, item)
                else
"""

if __name__ == '__main__':
    A = "#...\n#...\n#...\n#...\n"
    B = "#...\n##..\n.#..\n....\n"
    C = "##..\n##..\n....\n....\n"
    D = "#...\n###.\n....\n....\n"
    a = Item(A, 'A')
    b = Item(B, 'B')
    c = Item(C, 'C')
    d = Item(D, 'D')
    # print(a)
    # print(b)
    # print(c)
    # print(d)
    m = Map([a, b, c, d])
    m.fill()
    # m.print()
