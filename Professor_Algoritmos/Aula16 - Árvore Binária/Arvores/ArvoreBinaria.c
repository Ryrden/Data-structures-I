#include "ArvoreBinaria.h"
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st {
    ITEM *item;
    NODE *direita;
    NODE *esquerda;
};

struct arvore_binaria {
    NODE *raiz;
    int profundidade;
};

static void arvore_binaria_pre_ordem_recursao(NODE *raiz);

ARVORE_BINARIA *arvore_binaria_criar() {
    ARVORE_BINARIA *arvore;
    arvore = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));
    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

static void pre_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        item_imprimir(raiz->item);
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
    }
}

static void em_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pre_ordem_recursao(raiz->esquerda);
        item_imprimir(raiz->item);
        pre_ordem_recursao(raiz->direita);
    }
}

static void pos_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pre_ordem_recursao(raiz->esquerda);
        pre_ordem_recursao(raiz->direita);
        item_imprimir(raiz->item);
    }
}

void arvore_binaria_pre_ordem(ARVORE_BINARIA *arvoreBinaria) {
    pre_ordem_recursao(arvoreBinaria->raiz);
}

void arvore_binaria_em_ordem(ARVORE_BINARIA *arvoreBinaria) {
    em_ordem_recursao(arvoreBinaria->raiz);
}

void arvore_binaria_pos_ordem(ARVORE_BINARIA *arvoreBinaria) {
    pos_ordem_recursao(arvoreBinaria->raiz);
}

NODE *ab_inserir_no(NODE *raiz, ITEM *item, int lado, int chave) {
    if (raiz != NULL) {
        raiz->esquerda = ab_inserir_no(raiz->esquerda, item, lado, chave);
        raiz->direita = ab_inserir_no(raiz->direita, item, lado, chave);
        if (chave == item_get_chave(raiz->item)) {
            if (lado == FILHO_ESQ) {
                if (raiz->esquerda == NULL) {
                    raiz->esquerda = ab_cria_no(item);
                }
            } else if (lado == FILHO_DIR) {
                if (raiz->direita == NULL) {
                    raiz->direita = ab_cria_no(item);
                }
            }
        }
    }
    return raiz;
}

boolean ab_inserir(ARVORE_BINARIA *T, ITEM *item, int lado, int chave) {
    if (T->raiz == NULL)
        return ((T->raiz = ab_cria_no(item)) != NULL);
    else
        return ((T->raiz = ab_inserir_no(T->raiz, item, lado, chave)) != NULL);
}
