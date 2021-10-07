#include <stdlib.h>
#include "../Lista/Lista.h"

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE* proximo;
};

struct lista {
    NODE* inicio;
    NODE* fim;
    int tamanho;
};

LISTA *lista_criar()
{
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
    if(lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

boolean lista_vazia(const LISTA *lista)
{
    if(lista != NULL)
    {
        return lista->inicio == NULL;
    }
    return ERRO;
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
                lista->inicio = novoNode;
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
        NODE *nodeAtual;
        nodeAtual = lista->inicio;
        while(nodeAtual != NULL)
        {
            if(item_get_chave(nodeAtual->item) == chave)
            {
                return nodeAtual->item;
            }
            nodeAtual = nodeAtual->proximo;
        }
    }
    return NULL;
}

boolean lista_remover_item(LISTA *lista, int chave) {
    if (lista != NULL) {
        NODE *nodeAtual;
        NODE *nodeAnterior = NULL;
        nodeAtual = lista->inicio;
        while(nodeAtual != NULL && (item_get_chave(nodeAtual->item) != chave))
        {
            nodeAnterior = nodeAtual;
            nodeAtual = nodeAtual->proximo;
        }
        if(nodeAtual != NULL)
        {
            if(nodeAtual == lista->inicio)
            {
                lista->inicio = nodeAtual->proximo;
            }
            else
            {
                nodeAnterior->proximo = nodeAtual->proximo;
            }
            nodeAtual->proximo = NULL;
            if(lista->fim == nodeAtual)
            {
                lista->fim = nodeAnterior;
            }
            lista->tamanho--;
            free(nodeAtual);
            nodeAtual = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

