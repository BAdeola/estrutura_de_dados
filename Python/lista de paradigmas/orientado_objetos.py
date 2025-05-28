class Numeros:
    nums = []
    
    def __init__(self, lista):
        self.nums=lista

    def maior(self):
        return max(self.nums)
    
    def menor(self):
        return min(self.nums)
    

if __name__ == "__main__":
    lista = Numeros([int(x) for x in input().split()])
    print(f'Maior: {lista.maior()}')
    print(f'Menor: {lista.menor()}')