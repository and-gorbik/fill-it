from time import time

class extimer:
    def __init__(self, mes='Execution time: '):
        self._start = time()
        self._message = mes

    def __enter__(self):
        return

    def __exit__(self, *args):
        print('{}{}'.format(self._message, time() - self._start))

if __name__ == '__main__':

    def fib(n):
        return fib(n - 2) + fib(n - 1) if n > 1 else 1

    with extimer():
        print("Result: {}".format(fib(5)))

