from item import Item

class Map:
    def __init__(self, size=2):
        self._resize_map(size)
        self._curi, self._curj = 0, 0
        self._placed_items = []

    def print(self):
        for line in self._data:
            print("".join(line))

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
                    self._placed_items.append((item, di, dj))
                    for i, j in item.points:
                        self._data[i + di][j + dj] = item.chr
                    return (di, dj)
        return None

    def _remove_prev_item(self):
        item, di, dj = self._placed_items.pop()
        for i, j in item.points:
            self._data[i + di][j + dj] = '.'
        return item, di, dj

    def fill(self, figures):
        size = len(figures)
        while len(figures):
            ret = self._add_item(figures[0])
            if ret is not None:
                figures.pop(0)
                self._curi, self._curj = ret
            elif size != len(figures):
                item, self._curi, self._curj = self._remove_prev_item()
                figures.insert(0, item)
            else:
                self._resize_map(self.size + 1)
                self._curi, self._curj = 0, 0

if __name__ == '__main__':
    m = Map()
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
    m.fill([a, b, c, d])
    m.print()
