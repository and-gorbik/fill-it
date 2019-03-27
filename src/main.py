from sys import argv
from solver import Solver

s = Solver(filename=argv[1])
s.run()
s.response()
