#include <stdio.h>
#include "arvore.h"

int main(){
    int i, qtd, j, tam_arv, num;
    scanf("%d", &qtd);

    for(i = 0; i < qtd; i++){
        no arvore[100];

        scanf("%d",&tam_arv);
        for(j = 0; j < tam_arv; j++){
            scanf("%d", &num);
            insere_ordenado(arvore, j, num, &arvore[0]);
        }

        printf("Case %d:\n",i+1);
        printf("Pre.:");
        print_pre(arvore);
        printf("\n");
        printf("In..:");
        print_in(arvore);
        printf("\n");
        printf("Post:");
        print_post(arvore);
        printf("\n\n");
    }
    
    return 0;
}