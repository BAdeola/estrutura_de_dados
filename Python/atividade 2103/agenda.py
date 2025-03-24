agenda={}

def inserir():
    chave=input("Digite a data da agenda: ")
    while chave in agenda.keys():
        print("Data já inserida na agenda, insira uma nova data")
        chave=input("Digite a data da agenda: ")

    valor=float(input("Digite o valor do pagamento: "))

    agenda.update({chave : valor})
    return

def excluir():
    chave=input("Digite a data do valor que deseja excluir: ")
    try:    
        del agenda[chave]
    except KeyError:
        print("Data não existe na agenda.")
    return

def exibir():
    for key, value in agenda.items():
        print(f"Data: {key}")
        print(f"Valor: {value}\n")
    
    return

if __name__ == "__main__":
    v=0

    while v!=4:
        try:
            print("Digite '1' para inserir os valores na agenda")
            print("Digite '2' para excluir um valor da agenda")
            print("Digite '3' para ver a lista")
            print("Digite '4' para sair do programa\n")

            v=int(input("Digite uma opção: "))
            print()

        except ValueError:
            print("Inserção inválida, insira um valor entre 1 e 4")
            continue

        if v == 1:
            inserir()
        elif v == 2:
            excluir()
        elif v == 3:
            exibir()
        elif v == 4:
            print("Saindo do programa...")
        else:
            print("Opção inválida, insira um valor entre 1 e 4")