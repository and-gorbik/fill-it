class Item:
    def __init__(self, src, chr):
        self._src = src.replace('#', chr)
        self.chr = chr
        self.points, self.width, self.height = self._parse_to_set(chr)

    def __str__(self):
        return self._src

    def _parse_to_set(self, chr):
        result, i, j, h, w = set(), 0, 0, 0, 0
        for c in self._src:
            if c in '\n':
                i, j = i + 1, 0
            elif c in chr:
                result.add((i, j))
                h, w = max(h, i), max(w, j)
                j += 1
            else:
                j += 1
        return result, w + 1, h + 1

    def is_correct(self):
        return self.width == self.height


if __name__ == '__main__':
    s = "##..\n##..\n....\n....\n"
    i = Item(s, 'A')
    print(i)
    print(i.points)
    print(i.width)
    print(i.height)
    print("is correct?", i.is_correct())