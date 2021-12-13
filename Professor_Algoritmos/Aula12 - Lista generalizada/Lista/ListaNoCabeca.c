#include <stdlib.h>
#include "../Lista/Lista.h"

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE* proximo;
};

struct lista {
    NODE* cabeca;
    NODE* fim;
    int tamanho;
};

LISTA *lista_criar()
{
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
    if(lista != NULL)
    {
        lista->cabeca = (NODE*) malloc(sizeof(NODE));
        if(lista->cabeca == NULL)
        {
            return NULL;
        }
        lista->cabeca->proximo = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

boolean lista_vazia(const LISTA *lista)
{
    if((lista != NULL) && (lista->cabeca->proximo == NULL))
    {
        return TRUE;
    }
    return FALSE;
}

int lista_tamanho(const LISTA *lista) {
    if(lista != NULL)
    {
        return lista->tamanho;
    }
    return ERRO;
}

int lista_inserir(LISTA *lista, ITEM *item)
{
    if(lista != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->proximo = NULL;
            if(lista_vazia(lista))
            {
                lista->cabeca->proximo = novoNode;
            }
            else
            {
                lista->fim->proximo = novoNode;
            }
            lista->fim = novoNode;
            lista->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

ITEM *lista_busca_sequencial(const LISTA *lista, int chave) {
    if (lista != NULL) {
        NODE *noAtual;
        noAtual = lista->cabeca->proximo;
        while(noAtual != NULL)
        {
            if(item_get_chave(noAtual->item) == chave)
            {
                return noAtual->item;
            }
            noAtual = noAtual->proximo;
        }
    }
    return NULL;
}

boolean lista_remover_item(LISTA *lista, int chave) {
    if (lista != NULL) {
        NODE *nodeAtual;
        nodeAtual = lista->cabeca;
        while((nodeAtual->proximo != NULL) && (item_get_chave(nodeAtual->proximo->item) != chave))
        {
            nodeAtual = nodeAtual->proximo;
        }
        if(nodeAtual->proximo != NULL)
        {
            NODE *nodeRemovido;
            nodeRemovido = nodeAtual->proximo;
            nodeAtual->proximo = nodeRemovido->proximo;
            nodeRemovido->proximo = NULL;
            if(nodeAtual == lista->fim)
            {
                lista->fim = nodeAtual;
            }
            lista->tamanho--;
            free(nodeRemovido);
            nodeRemovido = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

ITEM *lista_busca_ordenada(const LISTA *lista, int chave) {
    if (lista != NULL)
    {
        NODE *nodeAtual = lista->cabeca->proximo;
        while (nodeAtual != NULL && (item_get_chave(nodeAtual->item) < chave))
        {
            nodeAtual = nodeAtual->proximo;
            if (item_get_chave(nodeAtual->item) == chave)
            {
                return nodeAtual->item;
            }
        }
    }
    return NULL;
}

int lista_inserir_ordenado(LISTA *lista, ITEM *i)
{
    NODE *nodeAtual = NULL;
    NODE *nodeNovo = NULL;
    if(lista != NULL && (!lista_cheia(lista)) )
    {
        nodeAtual = lista->cabeca;
        while((nodeAtual->proximo != NULL) && (item_get_chave(nodeAtual->proximo->item) < item_get_chave(i)))
        {
            nodeAtual = nodeAtual->proximo;
        }
        nodeNovo = (NODE *) malloc (sizeof(NODE));
        if(nodeNovo != NULL)
        {
            nodeNovo->item = i;
            nodeNovo->proximo = nodeAtual->proximo;
            nodeAtual->proximo = nodeNovo;
            if (nodeNovo->proximo == NULL) {
                lista->fim = nodeNovo;
            }
            lista->tamanho++;
            return TRUE;
        }
    }
    return FALSE;
}