import math
from functools import reduce

fatorial = lambda x: float(math.factorial(int(x)))
saida = lambda x: print(fatorial(x))

entrada = [float(x) for x in input().split()]
list(map(saida, entrada))