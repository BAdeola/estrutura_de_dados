from functools import reduce

#Entre com uma sequencia de números inteiros na mesma linha, exiba a soma somente
#dos números pares da sequencia digitada.

par = lambda x: True if x%2 == 0 else False
pares = lambda l: list(filter(par, l))
somar = lambda x, y: x + y
somaLista = lambda l: reduce(somar, l)

entrada = [int(x) for x in input().split()]
print(somaLista(pares(entrada)))