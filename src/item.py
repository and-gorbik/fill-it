class Item:
    def __init__(self, src: str, chr: str):
        """ src is a valid string, if it contains only chr symbols and 4 '\n' symbols """
        self._posi, self._posj = 0, 0
        self.chr = chr
        self._valid = (src.count('\n') == 5 and src.count('#') == 4 and src.count('.') == 12)
        self._data = self._to_matrix(src.replace('#', chr))
        self.points = self._set_points()
        self._validate()

    def __str__(self):
        # return self._src        

    def _to_matrix(self, src: str):
        if self._valid:
            matrix = [line for line in src.split('\n')][:-1]
            for line in matrix:
                if len(line) != 4:
                    self._valid = False
                    return None
            return matrix
        return None

    def _get_offset(self):
        dj = min([line.find(self.chr) for line in self._data]) + 1
        i, di = 0, 0
        while not self._data[i].count(self.chr):
            di += 1
        return di, dj

    def _set_points(self):
        if self._data is None:
            return None
        di, dj = self._get_offset()
        points = set()
        for i in range(4):
            for j in range(4):
                if self._data[i][j] in self.chr:
                    points.add((i - di, j - dj))
        return points

    def _validate():
        """ check figure correctness """
        if self._data is None:
            return
        # проверка фигуры на валидность
        self._valid = True

    def is_valid(self):
        return self._valid

    def set_position(self, i, j):
        self._posi, self._posj = i, j
    
    def get_position(self):
        return self._posi, self._posj

if __name__ == '__main__':
    s = "##..\n##..\n....\n....\n"
    i = Item(s, 'A')
    print(i)
    print(i.points)
    print("is correct?", i.is_valid())