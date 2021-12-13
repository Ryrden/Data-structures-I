#ifndef TADGENERICO_LISTAENCADEADA_H
#define TADGENERICO_LISTAENCADEADA_H

#include "EstruturaGenerica.h"
#include "Item.h"

ESTRUTURA_GENERICA* lista_criar();
int lista_inserir(ESTRUTURA_GENERICA *lista, ITEM* item);
boolean lista_inserir_posicao(ESTRUTURA_GENERICA *lista, int posicao, ITEM *item);
boolean lista_apagar(ESTRUTURA_GENERICA **lista);
ITEM* lista_remover(ESTRUTURA_GENERICA* lista);
boolean lista_remover_item(ESTRUTURA_GENERICA* lista, int chave);
int lista_tamanho(const ESTRUTURA_GENERICA *lista);
boolean lista_vazia(const ESTRUTURA_GENERICA* lista);
boolean lista_cheia(const ESTRUTURA_GENERICA* lista);
void lista_imprimir(const ESTRUTURA_GENERICA *lista);
ITEM *lista_busca_sequencial(const ESTRUTURA_GENERICA *lista, int chave);
ITEM *lista_busca_ordenada(const ESTRUTURA_GENERICA *lista, int chave);
int lista_inserir_ordenado(ESTRUTURA_GENERICA *lista, ITEM *i);


#endif //TADGENERICO_LISTAENCADEADA_H
