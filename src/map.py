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

    def unplaced_items(self):
        return self._items


class Map:
    def __init__(self, items, size=2):
        self._container = MapContainer(items)
        self._resize_map(size)
        # self._reset_position()

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
        return False

    def _remove_item(self):
        item = self._container.pop()
        curi, curj = item.get_position()
        for i, j in item.points:
            self._data[i + curi][j + curj] = '.'
        item.set_position(curi + 1, curj + 1)

    # def _next_position(self):
    #     if self._curj + 1 < self.size:
    #         self._curj += 1
    #         return True
    #     if self._curi + 1 < self.size:
    #         self._curi += 1
    #         self._curj = 0
    #         return True
    #     return False

    # def __next__(self):
    #     if self._curj + 1 < self.size:
    #         self._curj += 1
    #         return self._curi, self._curj
    #     if self._curi + 1 < self.size:
    #         self._curi += 1
    #         self._curj = 0
    #         return self._curi, self._curj
    #     raise StopIteration

    # def __iter__(self):
    #     return self

    # def _reset_position(self):
    #     self._curi, self._curj = 0, -1


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
