#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Item.h"

struct item_st
{   int chave;
    char nome[20];
    float valor;
};

ITEM *item_criar (int chave, const char *nome, float valor)
{
    ITEM *item;

    item = (ITEM *) malloc(sizeof(ITEM));

    if (item != NULL)
    {
        item->chave = chave;
        strcpy(item->nome, nome);
        item->valor = valor;
        return item;
    }
    return NULL;
}

boolean item_apagar(ITEM **item)
{
    if (*item != NULL)
    {
        (*item)->chave = ERRO; /*apaga o item simbolicamente*/
        free (*item);
        *item = NULL;
        return TRUE;
    }
    return FALSE;
}

int item_get_chave(const ITEM *item)
{
    if (item != NULL)
    {
        return item->chave;
    }
    return ERRO;
}


boolean item_set_chave(ITEM *item, int chave)
{
    if (item != NULL){
        item->chave = chave;
        return TRUE;
    }
    return FALSE;
}


void item_imprimir(const ITEM *item)
{
    if (item != NULL)
    {
        printf("\n-->item: %d\n", item->chave);
        printf("\n-->nome: %s\n", item->nome);
        printf("\n-->valor: %f\n", item->valor);
    }
}
