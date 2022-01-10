#ifndef TADGENERICO_LISTACIRCULAR_H
#define TADGENERICO_LISTACIRCULAR_H

#include "EstruturaGenerica.h"
#include "../Item.h"

ESTRUTURA_GENERICA* lista_circular_criar();
int lista_circular_inserir(ESTRUTURA_GENERICA *lista, ITEM* item);
boolean lista_circular_inserir_posicao(ESTRUTURA_GENERICA *lista, int posicao, ITEM *item);
boolean lista_circular_apagar(ESTRUTURA_GENERICA **lista);
boolean lista_circular_remover(ESTRUTURA_GENERICA* lista);
boolean lista_circular_remover_item(ESTRUTURA_GENERICA* lista, int chave);
int lista_circular_tamanho(const ESTRUTURA_GENERICA *lista);
boolean lista_circular_vazia(const ESTRUTURA_GENERICA* lista);
boolean lista_circular_cheia(const ESTRUTURA_GENERICA* lista);
void lista_circular_imprimir(const ESTRUTURA_GENERICA *lista);
ITEM *lista_circular_busca_sequencial(const ESTRUTURA_GENERICA *lista, int chave);
ITEM *lista_circular_busca_ordenada(const ESTRUTURA_GENERICA *lista, int chave);
int lista_circular_inserir_ordenado(ESTRUTURA_GENERICA *lista, ITEM *i);


#endif //TADGENERICO_LISTACIRCULAR_H
