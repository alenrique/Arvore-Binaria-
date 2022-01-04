#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    ArvBin *raiz;
    raiz = criar_arvore();
    inserir_arvore(raiz, 9);
    inserir_arvore(raiz, 3);
    inserir_arvore(raiz, 55);
    inserir_arvore(raiz, 1);
    inserir_arvore(raiz, 12);
    inserir_arvore(raiz, 21);
    inserir_arvore(raiz, 42);
    inserir_arvore(raiz, 6);
    inserir_arvore(raiz, 7);
    printf("Arvore Impressa: ");
    em_ordem(raiz);
    int mai = maior_numero(raiz);
    printf("\nMaior Valor da Arvore: %d \n",mai);

    int num = total_folha(raiz);
    printf("Quantidade de Folhas da Arvore: %d \n",num);

    int n;
    n = 2;

    int nmen = n_menor_valor(raiz,n);
    printf("n-Esimo Menor Valor da Arvore(Com n = %d): %d \n",n,nmen);
    return 0;
}
