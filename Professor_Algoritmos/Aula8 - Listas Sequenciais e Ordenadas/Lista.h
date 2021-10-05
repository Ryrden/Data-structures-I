#ifndef LISTA_H
#define LISTA_H

#include "Util.h"
#include "Item.h"

#define TAM_MAX 100 /*estimativa do tamanho máximo da valores*/
#define INICIO 0
#define ERRO (-32000)


typedef struct lista LISTA;

LISTA* lista_criar();
int lista_inserir(LISTA *lista, ITEM* item);
boolean lista_inserir_posicao(LISTA *lista, int posicao, ITEM *item);
boolean lista_apagar(LISTA **lista);
boolean lista_remover(LISTA* lista);
int lista_tamanho(const LISTA *lista);
boolean lista_vazia(const LISTA* lista);
boolean lista_cheia(const LISTA* lista);
void lista_imprimir(const LISTA *lista);
ITEM *lista_busca_sequencial(const LISTA *lista, int chave);
ITEM *lista_busca_ordenada(const LISTA *lista, int chave);


#endif //LISTA_H

