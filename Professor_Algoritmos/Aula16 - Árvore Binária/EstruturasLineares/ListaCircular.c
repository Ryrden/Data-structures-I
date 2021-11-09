#include <stdlib.h>
#include <stdio.h>
#include "ListaCircular.h"

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE *proximo;
};

struct estrutura_generica{
    NODE *sentinela;
    NODE *fim;
    int tamanho;
};

boolean lista_circular_vazia(const ESTRUTURA_GENERICA* lista)
{
    //TODO implementar
    if(lista->tamanho > 0)
    {
        return FALSE;
    }
    return TRUE;
}

boolean lista_circular_apagar(ESTRUTURA_GENERICA **lista)
{
    //TODO implementar
    return TRUE;
}

ESTRUTURA_GENERICA *lista_circular_criar()
{
    printf("Criando Lista Circular\n");

    ESTRUTURA_GENERICA *lista = (ESTRUTURA_GENERICA*) malloc(sizeof(ESTRUTURA_GENERICA));
    if(lista != NULL)
    {
        lista->sentinela = (NODE*) malloc(sizeof(NODE));
        lista->sentinela->item = item_criar_vazio();
        if(lista->sentinela == NULL)
        {
            return NULL;
        }
        lista->sentinela->proximo = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

int lista_circular_inserir(ESTRUTURA_GENERICA *lista, ITEM *item)
{
    if(lista != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->proximo = lista->fim->proximo;
            if(lista_circular_vazia(lista))
            {
                lista->sentinela->proximo = novoNode;
            }
            lista->fim = novoNode;
            lista->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

ITEM *lista_circular_busca_sequencial(const ESTRUTURA_GENERICA *lista, int chave) {
    item_set_chave(lista->sentinela->item, chave);
    NODE *nodeAtual = lista->sentinela;
    do {
        nodeAtual = nodeAtual->proximo;
    } while (item_get_chave(nodeAtual->item) != chave);
    return ((nodeAtual != lista->sentinela) ? nodeAtual->item : NULL);
}

ITEM *lista_circular_busca_ordenada(const ESTRUTURA_GENERICA *lista, int chave) {
    if (lista != NULL)
    {
        item_set_chave(lista->sentinela->item, chave);
        NODE *nodeAtual = lista->sentinela;
        int chaveAtual;
        do {
            nodeAtual = nodeAtual->proximo;
            chaveAtual = item_get_chave(nodeAtual->item);
        } while (chaveAtual != chave && (chaveAtual < chave));
        return ((nodeAtual != lista->sentinela) ? nodeAtual->item : NULL);
    }
    return NULL;
}

boolean lista_circular_cheia(const ESTRUTURA_GENERICA* lista)
{
    //TODO implementar
    return TRUE;
}

int lista_circular_inserir_ordenado(ESTRUTURA_GENERICA *lista, ITEM *item)
{
    if(lista != NULL && (!lista_circular_cheia(lista)) ) {
        item_set_chave(lista->sentinela->item, item_get_chave(item));
        NODE *nodeAtual = lista->sentinela;
        do {
            nodeAtual = nodeAtual->proximo;
        } while (item_get_chave(nodeAtual->item) < item_get_chave(item));

        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->proximo = nodeAtual->proximo;
            if (lista_circular_vazia(lista)) {
                lista->sentinela->proximo = novoNode;
            }
            if (lista->fim == nodeAtual) {
                lista->fim = novoNode;
            }
            nodeAtual->proximo = novoNode;
            lista->tamanho++;
            return TRUE;
        }
    }
    return FALSE;
}
