#Jogo da velha, entre com três linhas, cada linha com uma sequencia de 3 caracteres O ou
#X. Exiba na tela se houve empate ou vencedor, e quem foi esse vencedor O ou X.

def verificarLinhas(tabuleiro):
    for linha in tabuleiro:
        if linha[0] == linha[1] == linha[2] and linha[0] in ['X', 'O']:
            return linha[0]
    return None

def verificarDiagonais(tabuleiro):
    if tabuleiro[0][0] == tabuleiro[1][1] == tabuleiro[2][2] and tabuleiro[0][0] in ['X', 'O']:
        return tabuleiro[0][0]
    
    if tabuleiro[0][2] == tabuleiro[1][1] == tabuleiro[2][0] and tabuleiro[0][2] in ['X', 'O']:
        return tabuleiro[0][2]

def verificarColunas(tabuleiro):
    for i in range(3):
        if tabuleiro[0][i] == tabuleiro[1][i] == tabuleiro[2][i] and tabuleiro[0][i] in ['X', 'O']:
            return tabuleiro[0][i]
        
if __name__ == "__main__":
    fila1 = input().split()
    fila2 = input().split()
    fila3 = input().split()

    tabuleiro = [fila1, fila2, fila3]

    vencedor = verificarLinhas(tabuleiro)
    if not vencedor:
        vencedor = verificarDiagonais(tabuleiro)
    if not vencedor:
        vencedor = verificarColunas(tabuleiro)

    if vencedor:
        print(f'O vencerdor é: {vencedor}')
    else:
        print('Empate.')