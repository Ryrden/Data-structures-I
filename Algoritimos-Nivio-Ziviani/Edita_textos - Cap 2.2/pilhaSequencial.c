#include "pilhaSequencial.h"
#include <stdio.h>
#include <stdlib.h>

struct item_st {
    int chave;
};

struct pilha_st {
    ITEM item[MaxTam];
    apontador topo;
};

void FPvazia(PILHA *pilha) {
    pilha->topo = 0;
}

int vazia(PILHA pilha) {
    return (pilha.topo == 0);
}

void empilha(ITEM x, PILHA *pilha) {
    if (pilha->topo == MaxTam) {
        printf("Erro: pilha está cheia\n");
    } else {
        pilha->topo++;
        pilha->item[pilha->topo - 1] = x;
    }
}

void desempilha(PILHA *pilha, ITEM *item) {
    if (vazia(*pilha)) {
        printf("Erro: pilha está vazia\n");
    } else {
        *item = pilha->item[pilha->topo - 1];
        pilha->topo--;
    }
}

int tamanho(PILHA pilha) {
    return pilha.topo;
}

void imprime(PILHA *pilha) {
    PILHA pilhaux;
    ITEM x;
    FPvazia(&pilhaux);
    while (!vazia(*pilha)) {
        desempilha(pilha, &x);
        empilha(x, &pilhaux);
    }

    while (!vazia(pilhaux)) {
        desempilha(&pilhaux, &x);
        putchar(x.chave);
    }
    putchar('\n');
}