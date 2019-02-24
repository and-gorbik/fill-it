from sys import stderr
from math import sqrt, ceil

from item import Item
from extimer import extimer

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

    def unplaced_items(self):
        return self._items


class Map:
    def __init__(self, items):
        self._container = MapContainer(items)
        self._size = ceil(2 * sqrt(len(items)))
        self._resize_map(self._size)

    def __str__(self):
        return "\n".join(["".join(line) for line in self._data])

    def fill(self):
        while  not self._container.is_full():
            if not self._place_item():
                if self._container.is_empty():
                    self._resize_map(self.size + 1)
                else:
                    self._remove_item()

    def _resize_map(self, size):
        self.size = size
        self._data = [['.' for _ in range(size)] for _ in range(size)]
        for i in self._container.unplaced_items():
            i.set_position(0, 0)


    def _check_position(self, curi, curj):
        for i, j in self._container.next().points:
            if (i + curi >= self.size) or (j + curj >= self.size):
                return False
            if self._data[i + curi][j + curj] not in '.':
                return False
        return True

    def _place_item(self):
        curi, curj = self._container.next().get_position()
        while curi < self.size:
            while curj < self.size:
                if self._check_position(curi, curj):
                    item = self._container.push()
                    for i, j in item.points:
                        self._data[i + curi][j + curj] = item.chr
                    item.set_position(curi, curj)
                    print(self, '\n')
                    return True
                curj += 1
            curi += 1
            curj = 0
        self._container.next().set_position(0, 0)
        return False

    def _remove_item(self):
        item = self._container.pop()
        curi, curj = item.get_position()
        for i, j in item.points:
            self._data[i + curi][j + curj] = '.'
        if curj + 1 < self.size:
            item.set_position(curi, curj + 1)
        elif curi + 1 < self.size:
            item.set_position(curi + 1, curj)


class Optimizer:
    def __init__(self):
        self._vector_i = []
        self._vector_j = []
        self._table = []
        self._size = 0

    def _calculate_cell(self, i, j):
        result = 0
        if j - 1 >= 0 and self._table[i][j - 1] != 0:
            result += 1
        if j + 1 < self._size and self._table[i][j + 1] != 0:
            result += 1
        if i - 1 >= 0 and self._table[i - 1][j] != 0:
            result += 1
        if i + 1 < self._size and self._table[i + 1][j] != 0:
            result += 1
        self._table[i][j] = result

    def init_map(self, size):
        if size < 2:
            print("Size must be >= 2!", file=stderr)
            size = 2
        self._size = size
        self._vector_i = [4 for _ in range(size)]
        self._vector_j = self._vector_i[:]
        self._table = [[4 for _ in range(size)] for _ in range(size)]
        for i in range(size):
            for j in range(size):
                if i == 0 or i == size - 1 or j == 0 or j == size - 1:
                    self._table[i][j] = 3
                    if (i == 0 or i == size - 1) and (j == 0 or j == size - 1):
                        self._table[i][j] = 2
                else:
                    self._table[i][j] = 4

    def set_item(self, item: Item):
        curi, curj = item.get_position()
        for i, j in item.points:
            pass

    def unset_item(self, item):
        pass

    def is_available_row(self, i):
        """ позволяет узнать, нужно ли проверять строку """

    def is_available_col(self, j):
        """ позволяет узнать, нужно ли проверять столбец """

    def __str__(self):
        return "\n".join(["".join(str(line)) for line in self._table])
        

if __name__ == '__main__':
    # A = "#...\n#...\n#...\n#...\n"
    # B = "####\n....\n....\n....\n"
    # C = "###.\n..#.\n....\n....\n"
    # D = ".##.\n##..\n....\n....\n"
    # E = "##..\n##..\n....\n....\n"
    # F = "##..\n.##.\n....\n....\n"
    # G = "##..\n.#..\n.#..\n.#..\n"
    # H = "###.\n.#..\n....\n....\n"
    # a = Item(A, 'A')
    # b = Item(B, 'B')
    # c = Item(C, 'C')
    # d = Item(D, 'D')
    # e = Item(E, 'E')
    # f = Item(F, 'F')
    # g = Item(G, 'G')
    # h = Item(H, 'H')
    # m = Map([a, b, c, d, e, f, g, h])
    # with extimer():
    #     m.fill()
    # print(m)
    o = Optimizer()
    o.init_map(5)
    o._calculate_cell(4, 4)
    print(o)
