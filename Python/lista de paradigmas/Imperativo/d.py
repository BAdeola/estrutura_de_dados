#Entre com duas sequencias numéricas de inteiros, cada sequência em uma linha, exiba
#na tela o maior número das duas sequências, e o menor número das duas sequencias.

entrada1 = [int(x) for x in input().split()]
entrada2 = [int(x) for x in input().split()]

todas = entrada1 + entrada2

print(f'O maior número da primeiro sequência é: {max(entrada1)}')
print(f'O maior número da segunda sequência é: {max(entrada2)}')
print(f'O maior número entre as duas sequencias é: {max(todas)}')