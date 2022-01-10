#include <stdlib.h>
#include <stdbool.h>
#include "Avl.h"

typedef struct node_st NODE;

static void avl_apagar_aux(NODE **raiz);
static NODE *avl_inserir_no_e_rotacionar(NODE *raiz, const ITEM *item);

static bool DesbalanceamentoEhNegativo(NODE *raiz);

static bool DesbalanceamentoEhPositivo(NODE *raiz);

static bool ItemEhMaior(const NODE *raiz, const ITEM *item);

static bool ItemEhMenor(const NODE *raiz, const ITEM *item);

static NODE *selecionar_e_executar_rotacao(NODE *raiz, const ITEM *item);

static NODE *inserir_no(NODE *raiz, const ITEM *item);

struct node_st
{
    ITEM *item;
    NODE *direita;
    NODE *esquerda;
    int altura;
};

struct avl
{
    NODE* raiz;
    int profundidade;
};

AVL *avl_criar() {
    AVL *arvore = (AVL *) malloc(sizeof(AVL));
    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

static void avl_apagar_aux(NODE **raiz) {
    if (*raiz != NULL) {
        avl_apagar_aux(&((*raiz)->esquerda));
        avl_apagar_aux(&((*raiz)->direita));
        item_apagar(&(*raiz)->item);
        free(*raiz);
    }
}

void avl_apagar(AVL **arvore) {
    avl_apagar_aux(&(*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}

int avl_altura_no(NODE* raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        return raiz->altura;
    }
}

NODE *avl_cria_no(ITEM *item) {
    NODE *no = (NODE *) malloc(sizeof (NODE));
    if (no != NULL) {
        no->altura = 0;
        no->direita = NULL;
        no->esquerda = NULL;
        no->item = item;
    }
    return no;
}

NODE *rodar_direita(NODE *a) {
    NODE *b = a->esquerda;
    a->esquerda = b->direita;
    b->direita = a;

    a->altura = max(avl_altura_no(a->esquerda),
                    avl_altura_no(a->direita)) + 1;
    b->altura = max(avl_altura_no(b->esquerda),
                    a->altura) + 1;
    return b;
}

NODE *rodar_esquerda(NODE *a) {
    NODE *b = a->direita;
    a->direita = b->esquerda;
    b->esquerda = a;

    a->altura = max(avl_altura_no(a->esquerda),
                    avl_altura_no(a->direita)) + 1;
    b->altura = max(avl_altura_no(b->direita),
                    a->altura) + 1;
    return b;
}

NODE *rodar_esquerda_direita(NODE *a)   {
    a->esquerda = rodar_esquerda(a->esquerda);
    return rodar_direita(a);
}

NODE *rodar_direita_esquerda(NODE *a)   {
    a->direita = rodar_direita(a->direita);
    return rodar_esquerda(a);
}

static NODE *avl_inserir_no_e_rotacionar(NODE *raiz, const ITEM *item) {
    raiz = inserir_no(raiz, item);

    raiz->altura = max(avl_altura_no(raiz->esquerda),
                       avl_altura_no(raiz->direita)) + 1;

    raiz = selecionar_e_executar_rotacao(raiz, item);

    return raiz;
}

//TODO: resolver problema do item const
static NODE *inserir_no(NODE *raiz, const ITEM *item) {
    if (raiz == NULL) {
        raiz = avl_cria_no(item);
    }
    else if (ItemEhMaior(raiz, item)) {
        raiz->direita = avl_inserir_no_e_rotacionar(raiz->direita, item);
    }
    else if (ItemEhMenor(raiz, item)) {
        raiz->esquerda = avl_inserir_no_e_rotacionar(raiz->esquerda, item);
    }
    return raiz;
}

static NODE *selecionar_e_executar_rotacao(NODE *raiz, const ITEM *item) {
    if (DesbalanceamentoEhNegativo(raiz)) {
        if (ItemEhMaior(raiz->direita, item)) {
            raiz = rodar_esquerda(raiz);
        }
        else {
            raiz = rodar_direita_esquerda(raiz);
        }
    }

    if (DesbalanceamentoEhPositivo(raiz)) {
        if (ItemEhMenor(raiz->esquerda, item))
            raiz = rodar_direita(raiz);
        else
            raiz = rodar_esquerda_direita(raiz);
    }
    return raiz;
}

static bool ItemEhMenor(const NODE *raiz, const ITEM *item) {
    return item_get_chave(item) < item_get_chave(raiz->item);
}

static bool ItemEhMaior(const NODE *raiz, const ITEM *item) {
    return item_get_chave(item) > item_get_chave(raiz->item);
}

static bool DesbalanceamentoEhPositivo(NODE *raiz) {
    return avl_altura_no(raiz->esquerda)
               - avl_altura_no(raiz->direita) == 2;
}

static bool DesbalanceamentoEhNegativo(NODE *raiz) {
    return avl_altura_no(raiz->esquerda)
               - avl_altura_no(raiz->direita) == -2;
}

boolean avl_inserir(AVL *arvore, const ITEM *item) {
    arvore->raiz = avl_inserir_no_e_rotacionar(arvore->raiz, item);
    return arvore->raiz != NULL;
}






