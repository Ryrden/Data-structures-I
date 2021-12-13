#include <stdlib.h>
#include <stdio.h>
#include "PilhaEncadeada.h"

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE* anterior;
};

struct estrutura_generica {
    NODE* topo;
    int tamanho;
};

static void pilha_remove_tudo(ESTRUTURA_GENERICA *const *pilha);

static void pilha_remove_topo(ESTRUTURA_GENERICA *const *pilha);

ESTRUTURA_GENERICA *pilha_criar()
{
    printf("Criando Pilha\n");
    ESTRUTURA_GENERICA *pilha = (ESTRUTURA_GENERICA*) malloc(sizeof(ESTRUTURA_GENERICA));
    if(pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

boolean pilha_vazia(const ESTRUTURA_GENERICA *pilha)
{
    if(pilha != NULL)
    {
        return pilha->tamanho == 0;
    }
    return ERRO_PILHA;
}

int pilha_tamanho(const ESTRUTURA_GENERICA *pilha) {
    if(pilha != NULL)
    {
        return pilha->tamanho;
    }
    return ERRO_PILHA;
}

int pilha_empilhar(ESTRUTURA_GENERICA *pilha, ITEM *item)
{
    if(pilha != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->anterior = pilha->topo;
            pilha->topo = novoNode;
            pilha->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

ITEM *pilha_topo(const ESTRUTURA_GENERICA *pilha) {
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        return pilha->topo->item;
    }
    return NULL;
}

ITEM *pilha_desempilhar(ESTRUTURA_GENERICA *pilha) {
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        NODE *desempilhado = pilha->topo;
        ITEM *item = pilha->topo->item;
        pilha->topo = pilha->topo->anterior;
        desempilhado->anterior = NULL;
        free(desempilhado);
        desempilhado = NULL;
        pilha->tamanho--;
        return item;
    }
    return NULL;
}

boolean pilha_apagar(ESTRUTURA_GENERICA **pilha)
{
    if ((*pilha != NULL) && (!pilha_vazia(*pilha)))
    {
        pilha_remove_tudo(pilha);
        free (*pilha);
        *pilha = NULL;
        return TRUE;
    }
    return FALSE;
}

static void pilha_remove_tudo(ESTRUTURA_GENERICA *const *pilha) {
    while((*pilha)->topo != NULL)
    {
        pilha_remove_topo(pilha);
    }
}

static void pilha_remove_topo(ESTRUTURA_GENERICA *const *pilha) {
    NODE *temporaryNode;
    temporaryNode = (*pilha)->topo;
    (*pilha)->topo = (*pilha)->topo->anterior;
    item_apagar(&temporaryNode->item);
    temporaryNode->anterior = NULL;
    free(temporaryNode);
    temporaryNode = NULL;
}
