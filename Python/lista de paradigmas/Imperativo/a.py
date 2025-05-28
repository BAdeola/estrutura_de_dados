#Usuário deve entrar com uma sequencia numérica de inteiros em uma linha, exiba na
#tela qual o maior, qual o menor, e calcule a média aritmética dos valores.

entrada = [int(x) for x in input().split()]

print(f'Soma: {sum(entrada)}')
print(f'Maior: {max(entrada)}')
print(f'Menor: {min(entrada)}')
print(f'Media: {sum(entrada)/len(entrada)}')