#ifndef ITEM_H
#define ITEM_H

#define TRUE 1
#define FALSE 0
#define boolean char
#define ERRO -32000

typedef struct item_st ITEM;

ITEM *item_criar (int chave, const char *nome, float valor);
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
int item_get_chave(const ITEM *item);
boolean item_set_chave(ITEM *item, int chave);

#endif //ITEM_H
