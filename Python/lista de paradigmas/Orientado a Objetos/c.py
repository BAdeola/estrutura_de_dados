class Quadrilatero:
    base : float
    altura : float

    def __init__(self, base, alt):
        self.altura = alt
        self.base = base

    def calcular_area(self):
        return self.altura * self.base

    def calcular_perimetro(self):
        return 2 * (self.base + self.altura)

class Quadrado(Quadrilatero):
    lado : float

    def __init__(self, lado):
        super().__init__(lado, lado)

class Trapezio(Quadrilatero):
    base_menor : float

    def __init__(self, base_maior, base_menor, alt):
        super().__init__(base_maior, alt)
        self.base_menor = base_menor

    def calcular_area(self):
        return ((self.base + self.base_menor) * self.altura) / 2
    
if __name__ == "__main__":
    obj1 = Quadrilatero(4, 6)
    obj2 = Quadrado(5)
    obj3 = Trapezio(8, 5, 4)

    formas = [obj1, obj2, obj3]

    soma_areas = sum(f.calcular_area() for f in formas)
    soma_perimetros = sum(f.calcular_perimetro() for f in formas)

    print(f"Soma das áreas: {soma_areas:.2f}")
    print(f"Soma dos perímetros: {soma_perimetros:.2f}")