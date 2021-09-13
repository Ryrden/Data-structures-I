#include "pilhaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct item_st {
    int chave;
};

struct celula_st {
    ITEM item;
    Apontador prox;
};

struct pilha_st {
    Apontador fundo, topo;
    int tamanho;
};

void FPvazia(PILHA *pilha) {
    pilha->topo = (Apontador)malloc(sizeof(CELULA));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
}

int vazia(PILHA pilha) {
    return pilha.topo == pilha.fundo;
}

void empilha(ITEM x, PILHA *pilha) {
    Apontador aux;
    aux = (Apontador)malloc(sizeof(CELULA));
    pilha->topo->item = x;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void desempilha(PILHA *pilha, ITEM *item) {
    Apontador q;
    if (vazia(*pilha)){
        printf("Erro: lista vazia\n");
        return;
    }
    q= pilha->topo;
    pilha->topo = q->prox;
    *item = q->prox->item;
    free(q);
    pilha->tamanho--;
}

int tamanho(PILHA pilha){
    return pilha.tamanho;
}
