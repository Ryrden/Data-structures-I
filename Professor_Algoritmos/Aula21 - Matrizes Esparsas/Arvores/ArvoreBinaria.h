#ifndef TADGENERICO_ARVOREBINARIA_H
#define TADGENERICO_ARVOREBINARIA_H

#include "../Item.h"

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct arvore_binaria ARVORE_BINARIA;

ARVORE_BINARIA *arvore_binaria_criar();
void arvore_binaria_pre_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_em_ordem(ARVORE_BINARIA *arvoreBinaria);
void arvore_binaria_pos_ordem(ARVORE_BINARIA *arvoreBinaria);
boolean arvore_binaria_inserir(ARVORE_BINARIA *T, ITEM *item, int lado, int chave);
boolean arvore_binaria_remover(ARVORE_BINARIA *T, int chave);
void arvore_binaria_imprimir(ARVORE_BINARIA *T);

#endif //TADGENERICO_ARVOREBINARIA_H
