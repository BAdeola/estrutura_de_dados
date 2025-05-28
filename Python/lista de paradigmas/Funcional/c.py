from functools import reduce

par = lambda x: True if x%2 == 0 else False
impar = lambda x: True if x%2 != 0 else False
impares = lambda l: list(filter(impar, l))
pares = lambda l: list(filter(par, l))
somar = lambda x, y: x + y
somaLista = lambda l: reduce(somar, l) #reduce ele soma um por vez, seria tipo: somar(somar(somar(....))), então ele aplica o resultado da soma com o próximo número

entrada = [int(x) for x in input().split()]
print(f'{impares(entrada)}\n{pares(entrada)}')
print(somaLista(pares(entrada)))