#include <malloc.h>
#include "Lista.h"

struct lista
{
    ITEM *valores[TAM_MAX];
    int inicio;
    int fim;
};

static boolean posicao_valida(const LISTA *l, int pos);

static void move_itens_a_direita(LISTA *l, int pos);

static void lista_remove_tudo(LISTA *lista);

LISTA *lista_criar()
{
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));
    if (lista != NULL)
    {
        lista->inicio = INICIO;
        lista->fim = lista->inicio;
    }
    return lista;
}

boolean lista_inserir(LISTA *lista, ITEM *item){

    if ((lista != NULL) && !lista_cheia(lista))
    {
        (lista->valores[lista->fim]) = item;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

boolean lista_cheia(const LISTA *lista)
{
    return lista->fim >= TAM_MAX;
}
boolean lista_vazia(const LISTA *lista)
{
    return lista->fim == INICIO;
}

boolean lista_inserir_posicao(LISTA *lista, int posicao, ITEM *item)
{
    if (!lista_cheia(lista) && posicao_valida(lista, posicao)) {
        move_itens_a_direita(lista, posicao);
        lista->valores[posicao] = item;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

ITEM *lista_busca_sequencial(const LISTA *lista, int chave)
{
    for (int i = 0; i < lista->fim; i++)
    {
        if (item_get_chave(lista->valores[i]) == chave)
        {
            return lista->valores[i];
        }
    }
    return NULL;
}

ITEM *lista_busca_ordenada(const LISTA *lista, int chave)
{
    for (int i = 0; i < lista->fim; i++)
    {
        if (item_get_chave(lista->valores[i]) == chave)
        {
            return (lista->valores[i]);
        }
        else if (item_get_chave(lista->valores[i]) > chave)
        {
            return NULL; //retorna erro – não está na valores – elemento > chave
        }
    }
    return NULL; //retorna erro – não está na valores - percorreu toda a valores
}


static boolean posicao_valida(const LISTA *l, int pos)
{
    return pos < l->fim;
}

static void move_itens_a_direita(LISTA *l, int pos)
{
    for (int i = (l->fim - 1); i >= pos; i--)
    {
        l->valores[i + 1] = l->valores[i];
    }
}

boolean lista_apagar(LISTA **lista)
{
    if ((*lista != NULL) && (!lista_vazia(*lista)))
    {
        lista_remove_tudo(*lista);
        free (*lista);
        *lista = NULL;
        return TRUE;
    }
    return FALSE;
}

static void lista_remove_tudo(LISTA *lista)
{
    for (int i = 0; i < lista->fim; ++i)
    {
        item_apagar(&lista->valores[i]);
        lista->valores[i] = NULL;
    }
    lista->fim = INICIO;
}
