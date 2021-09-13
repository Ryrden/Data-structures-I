#ifndef PILHA_H
#define PILHA_H

#define MaxTam 1000

typedef int apontador;

typedef struct item_st ITEM;

typedef struct pilha_st PILHA;

void FPvazia(PILHA *pilha);

int vazia(PILHA pilha);

void empilha(ITEM x, PILHA *pilha);

void desempilha(PILHA *pilha, ITEM *item);

int tamanho(PILHA pilha);

#endif