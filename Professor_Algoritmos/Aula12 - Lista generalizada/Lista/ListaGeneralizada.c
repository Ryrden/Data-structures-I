#include <stdlib.h>
#include "../Lista/Lista.h"

typedef struct node_st NODE;

struct lista{
    NODE *inicio;
    int profundidade;
    int tamanho;
};

#define TIPO_ATOMO 0
#define TIPO_SUB_LISTA 1

struct node_st{
    int tipo;
    union {
        ITEM *atomo;
        NODE *sublista;
    } info;
    void * item_generico;
    NODE *proximo;
};

ITEM *busca_recursiva(int chave, NODE *nodeAtual);

LISTA *lista_criar()
{
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
    if(lista != NULL)
    {
        lista->inicio = NULL;
        lista->tamanho = 0;
        lista->profundidade = 0;
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

int lista_inserir_lista(LISTA *lista, NODE* subLista)
{
    if(lista != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL)
        {
            novoNode->tipo = TIPO_SUB_LISTA;
            novoNode->info.sublista = subLista;
            novoNode->proximo = NULL;
            if(lista_vazia(lista))
            {
                lista->inicio = novoNode;
            }
            lista->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

int lista_inserir_generico(LISTA *lista, void *item, int tipo)
{
    if(lista != NULL)
    {
        NODE *novoNode = (NODE *) malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->tipo = tipo;
            if(tipo == TIPO_ATOMO)
            {
                novoNode->item_generico = (ITEM *)item;
                novoNode->info.atomo = (ITEM *)item;
            }
            else if(tipo == TIPO_SUB_LISTA)
            {
                novoNode->item_generico = (NODE *)item;
                novoNode->info.sublista = (NODE *)item;
            }
            novoNode->proximo = NULL;
            if(lista_vazia(lista))
            {
                lista->inicio = novoNode;
            }
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
        return busca_recursiva(chave, nodeAtual);
    }
    return NULL;
}

ITEM *busca_recursiva(int chave, NODE *nodeAtual) {
    while(nodeAtual != NULL)
    {
        if(nodeAtual->tipo == TIPO_ATOMO)
        {
            if(item_get_chave(nodeAtual->info.atomo) == chave)
            {
                return nodeAtual->info.atomo;
            }
        }
        else if(nodeAtual->tipo == TIPO_SUB_LISTA)
        {
            NODE* subLista = nodeAtual->info.sublista;
            ITEM* resultado = busca_recursiva(chave, subLista);
            if(resultado != NULL)
            {
                return resultado;
            }
        }
        nodeAtual = nodeAtual->proximo;
    }
    return NULL;
}

