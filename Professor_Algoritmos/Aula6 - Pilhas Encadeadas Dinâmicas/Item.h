#ifndef ITEM_H
#define ITEM_H

#include "Util.h"

#define ERRO (-32000)

typedef struct item_st ITEM;

ITEM *item_criar (int chave, const char *nome, int ataque, int defesa);
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
int item_get_chave(const ITEM *item);
boolean item_set_chave(ITEM *item, int chave);

#endif //ITEM_H
