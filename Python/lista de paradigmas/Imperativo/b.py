#Entre com uma sequencia de no mínimo 5 números reais, calcule a média ponderada,
#utilizando 0.3 para os dois primeiros valores e para os dois últimos valores, e a 0.1 para
#os valores intermediários, exiba o resultado. 

entrada = [float(x) for x in input().split()]

if len(entrada) < 5 or len(entrada) > 5:
    print('Entrada não suficiente')
else:
    pesos = []
    for i in range(len(entrada)):
        if i < 2 or i >= len(entrada)-2:
            pesos.append(0.3)
        else:
            pesos.append(0.1)

    somaPonderada = 0
    somaPesos = 0

    for i in range(len(entrada)):
        somaPonderada+=entrada[i] * pesos[i]
        somaPesos+=pesos[i]

    mediaPonderada = somaPonderada / somaPesos

    print(f'A média ponderada é: {mediaPonderada}')
