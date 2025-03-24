#ifndef _CIRCULO_H
#define _CIRCULO_H

/* Definição do tipo Circulo */
typedef struct {
   ponto centro;
   double raio;
} circulo;


/* Função circ_init
 * inicializa um círculo c com centro no ponto x,y e raio r */
void circ_init(circulo * c, int x, int y, double r)

/* Função circ_area
 * calcula e devolve a área do círculo c (πR²) */
double circ_area(circulo c);

/* Função circ_contains
 * verifica se um ponto p está dentro do círculo c (a distância do ponto ao centro do círculo é menor ou igual a seu raio) */
bool circ_contains(circulo c, ponto p)

#endif
