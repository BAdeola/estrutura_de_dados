#Entre com uma sequencia de 3 Strings, retorne todas as Strings no formato caixa alta, e
#indique qual delas possui a maior quantidade de caracteres.

entrada = input('Insira 3 strings separadas por espaço: ').split()

if len(entrada) < 3 or len(entrada) > 3:
    print('Valor de entrada errado, insira apenas 3 strings separadas por espaço.')
else:
    caixaAlta = [""] * 3
    maior = 0
    for i in range(len(entrada)):
        caixaAlta.append(entrada[i].upper())
        temp = len(entrada[i])
        if temp > maior:
            maior = temp
    
    for i in range(len(caixaAlta)):
        print(f'String {i}: {caixaAlta[i]}')
    print(f'A string com mais caracteres é: {maior}')