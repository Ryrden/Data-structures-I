#ifndef LIST_H
#define LIST_H

#include "util.h"
#define ERRO (-32000)

typedef struct list LIST;

LIST *list_criar();
int list_insert(LIST *list, void *item);
boolean list_inserir_posicao(LIST *list, int posicao, void *item);
boolean list_erase(LIST **list);
boolean list_remove(LIST *list);
boolean list_remover_item(LIST *list, int key);
int list_size(const LIST *list);
boolean list_empty(const LIST *list);
boolean list_full(const LIST *list);
void list_imprimir(const LIST *list);
void *list_busca_sequencial(const LIST *list, int key);
void *list_busca_ordenada(const LIST *list, int key);

#endif //LIST_H
