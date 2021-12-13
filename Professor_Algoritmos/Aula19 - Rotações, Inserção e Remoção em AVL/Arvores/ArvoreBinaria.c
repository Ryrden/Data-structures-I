#include "ArvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>

#define COUNT 8
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

static void pre_ordem_recursao(NODE *raiz);
static void em_ordem_recursao(NODE *raiz);
static void pos_ordem_recursao(NODE *raiz);
static NODE *cria_no(ITEM *item);
static void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant);
static boolean ehMaior(const NODE *raiz, const ITEM *item);
static boolean ehMenor(const NODE *raiz, const ITEM *item);
static boolean abb_remover_aux(NODE **raiz, int chave);

ARVORE_BINARIA *arvore_binaria_criar() {
    ARVORE_BINARIA *arvore;
    arvore = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));
    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

static NODE *cria_no(ITEM *item) {
    NODE *novoNode = (NODE *)malloc(sizeof(NODE));
    if (novoNode != NULL) {
        novoNode->item = item;
        novoNode->direita = NULL;
        novoNode->esquerda = NULL;
    }
    return novoNode;
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
        em_ordem_recursao(raiz->esquerda);
        item_imprimir(raiz->item);
        em_ordem_recursao(raiz->direita);
    }
}

static void pos_ordem_recursao(NODE *raiz) {
    if (raiz != NULL) {
        pos_ordem_recursao(raiz->esquerda);
        pos_ordem_recursao(raiz->direita);
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

NODE *ab_inserir_no(NODE *raiz, ITEM *item,
                    int lado, int chave) {
    if (raiz != NULL) {
        raiz->esquerda = ab_inserir_no(raiz->esquerda, item, lado, chave);
        raiz->direita = ab_inserir_no(raiz->direita, item, lado, chave);
        if (chave == item_get_chave(raiz->item)) {
            if (lado == FILHO_ESQ) {
                raiz->esquerda = cria_no(item);
            } else if (lado == FILHO_DIR) {
                raiz->direita = cria_no(item);
            }
        }
    }
    return raiz;
}

boolean arvore_binaria_inserir(ARVORE_BINARIA *T, ITEM *item, int lado, int chave) {
    if (T->raiz == NULL)
        return ((T->raiz = cria_no(item)) != NULL);
    else
        return ((T->raiz = ab_inserir_no(T->raiz, item, lado, chave)) != NULL);
}

int ab_profundidade(NODE *no) {
    if (no == NULL)
        return -1;
    int e = ab_profundidade(no->esquerda);
    int d = ab_profundidade(no->direita);
    return ((e > d) ? e : d) + 1;
}

void apagar_arvore(NODE **raiz) {
    if (*raiz != NULL) {
        apagar_arvore(&(*raiz)->esquerda);
        apagar_arvore(&(*raiz)->direita);
        item_apagar(&(*raiz)->item);
        free(*raiz);
        *raiz = NULL;
    }
}
void ab_apagar_arvore(ARVORE_BINARIA **T) {
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

NODE *abb_inserir_no(NODE *raiz, ITEM *item) {
    if (raiz == NULL)
        raiz = cria_no(item);
    else if (ehMaior(raiz, item))
        raiz->direita = abb_inserir_no(raiz->direita, item);
    else if (ehMenor(raiz, item))
        raiz->esquerda = abb_inserir_no(raiz->esquerda, item);
    return raiz;
}

boolean ehMenor(const NODE *raiz, const ITEM *item) {
    return item_get_chave(item) < item_get_chave(raiz->item);
}

boolean ehMaior(const NODE *raiz, const ITEM *item) {
    return item_get_chave(item) > item_get_chave(raiz->item);
}

boolean abb_inserir(ARVORE_BINARIA *T, ITEM *item) {
    return ((T->raiz = abb_inserir_no(T->raiz, item)) != NULL);
}

ITEM *abb_busca_no(NODE *raiz, int chave) {
    if (raiz == NULL)
        return NULL;
    if (chave == item_get_chave(raiz->item))
        return (raiz->item);
    if (chave < item_get_chave(raiz->item))
        return (abb_busca_no(raiz->esquerda, chave));
    else
        return (abb_busca_no(raiz->direita, chave));
}
ITEM *abb_busca(ARVORE_BINARIA *T, int chave) {
    return (abb_busca_no(T->raiz, chave));
}

static boolean abb_remover_aux(NODE **raiz, int chave) {
    NODE *noRemovido;
    if (*raiz == NULL) {
        return FALSE;
    }
    if (chave == item_get_chave((*raiz)->item)) {
        if ((*raiz)->esquerda == NULL || (*raiz)->direita == NULL) { /*Caso 1 se resume ao caso 2: há um filho ou nenhum*/
            noRemovido = *raiz;
            if ((*raiz)->esquerda == NULL) {
                *raiz = (*raiz)->direita;
            } else {
                *raiz = (*raiz)->esquerda;
            }
            free(noRemovido);
            noRemovido = NULL;
        } else /*Caso 3: há ambos os filhos*/
        {
            troca_max_esq((*raiz)->esquerda, (*raiz), (*raiz));
        }
        return TRUE;
    } else {
        if (chave < item_get_chave((*raiz)->item))
            return abb_remover_aux(&(*raiz)->esquerda, chave);
        else
            return abb_remover_aux(&(*raiz)->direita, chave);
    }
}

boolean arvore_binaria_remover(ARVORE_BINARIA *T, int chave) {
    if (T != NULL)
        return abb_remover_aux(&T->raiz, chave);
    return FALSE;
}

static void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant) {
    if (troca->direita != NULL) {
        troca_max_esq(troca->direita, raiz, troca);
        return;
    }
    if (raiz == ant) {
        ant->esquerda = troca->esquerda;
    } else {
        ant->direita = troca->esquerda;
    }
    raiz->item = troca->item;
    free(troca);
    troca = NULL;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
static void print2DUtil(NODE *root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->direita, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", item_get_chave(root->item));

    // Process left child
    print2DUtil(root->esquerda, space);
}

// Wrapper over print2DUtil()
void arvore_binaria_imprimir(ARVORE_BINARIA *root) {
    // Pass initial space count as 0
    print2DUtil(root->raiz, 0);
}
