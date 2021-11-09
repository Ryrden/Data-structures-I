#ifndef TADGENERICO_PILHAENCADEADA_H
#define TADGENERICO_PILHAENCADEADA_H

#include "Item.h"
#include "EstruturaGenerica.h"

#define TAM 100
#define ERRO_PILHA (-300)

ESTRUTURA_GENERICA* pilha_criar();
boolean pilha_vazia(const ESTRUTURA_GENERICA* pilha);
int pilha_tamanho(const ESTRUTURA_GENERICA *pilha);
int pilha_empilhar(ESTRUTURA_GENERICA *pilha, ITEM* item);
ITEM* pilha_topo(const ESTRUTURA_GENERICA *pilha);
ITEM* pilha_desempilhar(ESTRUTURA_GENERICA* pilha);
boolean pilha_apagar(ESTRUTURA_GENERICA **pilha);

#endif //TADGENERICO_PILHAENCADEADA_H
