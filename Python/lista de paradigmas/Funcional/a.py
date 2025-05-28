#Usuário deve entrar com uma sequencia numérica de inteiros, e deve exibir na telas duas
#linhas, uma linha com os números ímpares, e outra linha com os pares.

par = lambda x: True if x%2 == 0 else False
impar = lambda x: True if x%2 != 0 else False
impares = lambda l: list(filter(impar, l))
pares = lambda l: list(filter(par, l))

entrada = [int(x) for x in input().split()]
print(f'{impares(entrada)}\n{pares(entrada)}')