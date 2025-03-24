#include <stdio.h>
#include "pilhas.h"

bool casar_delimitador(char d1, char d2) {
    if (d1 == '(' && d2 == ')')
        return true;
    if (d1 == '[' && d2 == ']')
        return true;
    if (d1 == '{' && d2 == '}')
        return true;
    return false;
}

void print_erro(int lin, int col) {
    printf("Erro no arquivo (Linha: %d | Coluna: %d)!\n", lin, col);
    exit(1);
}

int main(){

    //exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    //exercicio5();
    //exercicio6();
    exercicio7();

    return 0;
}
