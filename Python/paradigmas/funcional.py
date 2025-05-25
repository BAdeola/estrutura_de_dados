par = lambda x: True if x%2 == 0 else False
impar = lambda x: True if x%2 != 0 else False
impares = lambda l: list(filter(impar, l))
pares = lambda l: list(filter(par, l))

entrada = [int(x) for x in input().split()]
print(f'{impares(entrada)}\n{pares(entrada)}')