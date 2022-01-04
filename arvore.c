#include <stdio.h>
#include <stdlib.h>
#include "arvore1.h"

struct NO{
    struct NO *esq;
    int dado;
    struct NO *dir;
};


ArvBin *criar_arvore(){
    ArvBin *raiz;
    raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int inserir_arvore(ArvBin *raiz, int num){
    struct NO *novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL){
        return 0;
    }
    novo->dado = num;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }
    else{
        struct NO *aux;
        struct NO *ant;
        aux = *raiz;
        ant = NULL;
        while(aux != NULL){
            ant = aux;
            if(num == aux->dado){
                free(novo);
                return 0;
            }
            if(num > aux->dado){
                aux = aux->dir;
            }
            else{
                aux = aux->esq;
            }
        }
        if(num > ant->dado){
            ant->dir = novo;
        }
        else{
            ant->esq = novo;
        }
        return 1;
    }
}

void em_ordem(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("[");
        em_ordem(&((*raiz)->esq));
        printf("%d",(*raiz)->dado);
        em_ordem(&((*raiz)->dir));
        printf("]");
    }
}

int maior_numero(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    struct NO *aux;
    aux = *raiz;
    while(aux->dir != NULL){
        aux = aux->dir;
    }
    return aux->dado;

}

int total_folha(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int res;
    int num_esq = total_folha(&((*raiz)->esq));
    int num_dir = total_folha(&((*raiz)->dir));
    res = (num_esq + num_dir);
    if((*raiz)->esq != NULL || (*raiz)->dir != NULL){
        return (res);
    }
    else{
        return (res + 1);
    }
}

int n_menor_valor(ArvBin *raiz, int n){
    int i;
    struct NO *aux;
    aux = *raiz;
    for(i = 1;i < n;i++){
        if(aux == NULL){
            break;
        }
        if(aux->esq != NULL){
            aux = aux->esq;
        }
        else{
            aux = aux->dir;
        }
    }
    if(aux != NULL){
        return aux->dado;
    }
    else{
        printf("Nao Existe \n");
    }
}


