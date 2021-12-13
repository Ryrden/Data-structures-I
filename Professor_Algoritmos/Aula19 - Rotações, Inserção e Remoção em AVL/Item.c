#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_st {
    int chave;
    char nome[30];
    char descricao[30];
    int ataque;
    int defesa;
};

ITEM *item_criar_vazio() {
    ITEM *item;

    item = (ITEM *)calloc(sizeof(ITEM), 1);
    return item;
}

ITEM *item_criar(int chave, const char *nome, const char *descricao, int ataque, int defesa) {
    ITEM *item;

    item = (ITEM *)malloc(sizeof(ITEM));

    if (item != NULL) {
        item->chave = chave;
        strcpy(item->nome, nome);
        item->ataque = ataque;
        item->defesa = defesa;
        strcpy(item->descricao, descricao);
        return item;
    }
    return NULL;
}

ITEM *item_ler_std_in() {
    ITEM item;
    scanf("%d", &(item.chave));
    scanf(" %[^(\r|\n)]*c", item.nome);
    scanf(" %[^(\r|\n)]*c", item.descricao);
    scanf("%d", &(item.ataque));
    scanf("%d", &(item.defesa));
    return item_criar(item.chave, item.nome, item.descricao, item.ataque, item.defesa);
}

boolean item_apagar(ITEM **item) {
    if (*item != NULL) {
        (*item)->chave = ERRO; /*apaga o item simbolicamente*/
        free(*item);
        *item = NULL;
        return TRUE;
    }
    return FALSE;
}

int item_get_chave(const ITEM *item) {
    if (item != NULL) {
        return item->chave;
    }
    return ERRO;
}

boolean item_set_chave(ITEM *item, int chave) {
    if (item != NULL) {
        item->chave = chave;
        return TRUE;
    }
    return FALSE;
}

void item_imprimir(const ITEM *item) {
    if (item != NULL) {
        printf("\n-->chave: %d", item->chave);
        printf("\n-->nome: %s__", item->nome);
        printf("\n-->descricao: %s__", item->descricao);
        printf("\n-->ataque: %d", item->ataque);
        printf("\n-->defesa: %d\n", item->defesa);
    }
}
