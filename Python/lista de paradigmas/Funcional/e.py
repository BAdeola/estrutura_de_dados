#Entre com 3 sequencias de números inteiros, uma sequencia em cada linha. Exiba na tela
#em uma linha a sequencia dos números em ordem crescente sem números iguais.

ler_linha = lambda: list(map(int, input().split()))
ler_tres_linhas = lambda f: list(map(lambda _: f(), range(3)))
achatar = lambda l: sum(l, [])
remover_repetidos = lambda l: set(l)
ordenar = lambda l: sorted(l)
imprimir = lambda l: print(*l)

entrada = achatar(ler_tres_linhas(ler_linha))
imprimir(ordenar(remover_repetidos(entrada)))