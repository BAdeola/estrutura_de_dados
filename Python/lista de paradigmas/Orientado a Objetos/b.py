class MediaPonderada: 
    def __init__(self, numeros):
        if len(numeros) < 5:
            raise ValueError("A sequência deve conter pelo menos 5 números.")
        self.numeros = numeros
        self.pesos = self._definir_pesos()

    def _definir_pesos(self):
        n = len(self.numeros)
        pesos = []
        for i in range(n):
            if i < 2 or i >= n-2:
                pesos.append(0.3)
            else:
                pesos.append(0.1)
        return pesos

    def calcular(self):
        total = sum(n * p for n, p in zip(self.numeros, self.pesos))
        soma_pesos = sum(self.pesos)
        return total / soma_pesos

    def exibir_resultado(self):
        resultado = self.calcular()
        print(f"Média ponderada: {resultado:.2f}")

if __name__ == "__main__":
    lista = MediaPonderada([int(x) for x in input().split()])
    lista.exibir_resultado()