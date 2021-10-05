#include <stdlib.h>
#include "../Lista/Lista.h"

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE *proximo;
};

struct lista{
    NODE *sentinela;
    NODE *fim;
    int tamanho;
};

LISTA *lista_criar()
{
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
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

int lista_inserir(LISTA *lista, ITEM *item)
{
    if(lista != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->proximo = lista->fim->proximo;
            if(lista_vazia(lista))
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

ITEM *lista_busca_sequencial(const LISTA *lista, int chave) {
    item_set_chave(lista->sentinela->item, chave);
    NODE *nodeAtual = lista->sentinela;
    do {
        nodeAtual = nodeAtual->proximo;
    } while (item_get_chave(nodeAtual->item) != chave);
    return ((nodeAtual != lista->sentinela) ? nodeAtual->item : NULL);
}

ITEM *lista_busca_ordenada(const LISTA *lista, int chave) {
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

int lista_inserir_ordenado(LISTA *lista, ITEM *item)
{
    if(lista != NULL && (!lista_cheia(lista)) ) {
        item_set_chave(lista->sentinela->item, item_get_chave(item));
        NODE *nodeAtual = lista->sentinela;
        do {
            nodeAtual = nodeAtual->proximo;
        } while (item_get_chave(nodeAtual->item) < item_get_chave(item));

        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->proximo = nodeAtual->proximo;
            if (lista_vazia(lista)) {
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
