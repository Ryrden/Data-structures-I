//
// Created by leotp on 04-Oct-21.
//

#include <stdlib.h>
#include <stdbool.h>
#include "../Lista/Lista.h"

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE *anterior;
    NODE *proximo;
};

struct lista {
    NODE* inicio;
    NODE* fim;
    int tamanho;
};

boolean is_list_start(const LISTA *lista, const NODE *noAtual);

NODE *getNodeWithKey(int chave, NODE *noAtual);

boolean deleteNode(LISTA *lista, NODE *noAtual);

bool listContainsSomething(const LISTA *lista);

boolean deleteNodeIfPossible(LISTA *lista, NODE *noAtual);

LISTA *lista_criar()
{
/*pré-condição: existir espaço na memória.*/
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

/*recebe o inicio da lista como argumento e esvazia a mesma*/
void lista_esvazia (NODE *noAtual){
    if (noAtual != NULL){
        if(noAtual->proximo != NULL)
        {
            lista_esvazia(noAtual->proximo);
        }
        item_apagar(&noAtual->item);
        noAtual->anterior = NULL;
        free(noAtual); /* apaga o nó*/
        noAtual = NULL;
    }
}

boolean lista_apagar(LISTA **lista){
    if (*lista == NULL)
        return FALSE;
    lista_esvazia((*lista)->inicio);
    free(*lista);
    *lista = NULL;
    return TRUE;
}

/*Insere um novo nó no início da lista. PARA LISTAS NÃO ORDENADAS*/
boolean lista_inserir_inicio(LISTA *lista, ITEM *i)
{
    if ((lista != NULL) && (!lista_cheia(lista)) )
    {
        NODE *pnovo = (NODE *) malloc(sizeof (NODE));
        if(pnovo != NULL)
        {
            pnovo->item = i;
            if (lista->inicio == NULL){
                lista->fim = pnovo;
                pnovo->proximo = NULL;
            }
            else {
                lista->inicio->anterior = pnovo;
                pnovo->proximo = lista->inicio;
            }
            pnovo->anterior = NULL;
            lista->inicio = pnovo;
            lista->tamanho++;
            return TRUE;
        }
    }
    return FALSE;
}

/*Insere um novo nó no fim da lista. PARA LISTAS NÃO ORDENADAS*/
boolean lista_inserir_fim(LISTA *lista, ITEM *item)
{
    if ((lista != NULL) && (!lista_cheia(lista)) )
    {
        NODE *pnovo = (NODE *) malloc(sizeof (NODE));
        if(pnovo != NULL) {
            pnovo->item = item;
            if (lista->inicio == NULL) {
                lista->inicio = pnovo;
                pnovo->anterior = NULL;
            } else {
                lista->fim->proximo = pnovo;
                pnovo->anterior = lista->fim;
            }
            pnovo->proximo = NULL;
            lista->fim = pnovo;
            lista->tamanho++;
            return TRUE;
        }
    }
    return FALSE;
}

boolean lista_remover_item(LISTA *lista, int chave){
    NODE *noAtual = NULL;
    if (listContainsSomething(lista)){
        noAtual = lista->inicio;
        /*Percorre a lista em busca da chave*/
        noAtual = getNodeWithKey(chave, noAtual);
        /*Se a lista não acabou significa que encontrou a chave*/
        boolean result;
        deleteNodeIfPossible(lista, noAtual);
    }
    return FALSE; /*elemento (chave) não está na lista ou lista vazia*/
}

boolean deleteNodeIfPossible(LISTA *lista, NODE *noAtual) {
    boolean result;
    if(noAtual != NULL)
    {
        result = deleteNode(lista, noAtual);
    }
    else
    {
        result = FALSE;
    }
    return result;
}

bool listContainsSomething(const LISTA *lista)
{
    return (lista != NULL) && (!lista_vazia(lista));
}

boolean deleteNode(LISTA *lista, NODE *noAtual) {/*Se é o 1º da lista basta acertar o ptr inicio*/
    if(is_list_start(lista, noAtual))
    {
        lista->inicio = noAtual->proximo;
    }
    /*Se não é o 1º da lista, há alguém antes dele para acertar o ptr*/
    else
    {
        noAtual->anterior->proximo = noAtual->proximo;
    }
    /* Ideia do if/else anterior para o fim da lista */
    if(noAtual == lista->fim)
    {
        lista->fim = noAtual->anterior;
    }
    else
    {
        noAtual->proximo->anterior = noAtual->anterior;
    }
    noAtual->proximo = NULL;
    noAtual->anterior = NULL;
    free(noAtual);
    lista->tamanho--;
    return TRUE;
}

NODE *getNodeWithKey(int chave, NODE *noAtual) {
    while(noAtual != NULL && (item_get_chave(noAtual->item) != chave) ) {
        noAtual = noAtual->proximo;
    }
    return noAtual;
}

boolean is_list_start(const LISTA *lista, const NODE *noAtual) {
    return noAtual == lista->inicio;
}

