#ifndef PILHA_H
#define PILHA_H

#include "Util.h"
#include "Item.h"

#define TAM 100
#define ERRO_PILHA (-300)

typedef struct pilha PILHA;

PILHA* pilha_criar();
boolean pilha_vazia(const PILHA* pilha);
boolean pilha_cheia(const PILHA *pilha);
int pilha_tamanho(const PILHA *pilha);
int pilha_empilhar(PILHA *pilha, ITEM* item);
ITEM* pilha_topo(const PILHA *pilha);
ITEM* pilha_desempilhar(PILHA* pilha);
boolean pilha_apagar(PILHA **pilha);

#endif //PILHA_H