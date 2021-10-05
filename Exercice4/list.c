#include "list.h"
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st {
    void *item;
    NODE *next;
};

struct list {
    NODE *start;
    NODE *end;
    int size;
};

LIST *create_list() {
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list != NULL) {
        list->start = NULL;
        list->end = NULL;
        list->size = 0;
    }
    return list;
}

boolean list_empty(const LIST *list) {
    if (list != NULL) {
        return list->start == NULL;
    }
    return ERRO;
}

int list_size(const LIST *list) {
    if (list != NULL) {
        return list->size;
    }
    return ERRO;
}

int list_insert (LIST *list, void *item) {
    if (list != NULL) {
        NODE *novoNode = (NODE *)malloc(sizeof(NODE));
        if (novoNode != NULL) {
            novoNode->item = item;
            novoNode->next = NULL;
            if (list_empty(list)) {
                list->start = novoNode;
            } else {
                list->end->next = novoNode;
            }
            list->end = novoNode;
            list->size++;
            return TRUE;
        }
    }
    return ERRO;
}

void *list_sequential_search(const LIST *list, int key) {
    if (list != NULL) {
        NODE *noAtual;
        noAtual = list->start;
        while (noAtual != NULL) {
            if (item_get_key(noAtual->item) == key) {
                return noAtual->item;
            }
            noAtual = noAtual->next;
        }
    }
    return NULL;
}

boolean list_remove_item(LIST *list, int key) {
    if (list != NULL) {
        NODE *noAtual;
        NODE *noAnterior = NULL;
        noAtual = list->start;
        while (noAtual != NULL && (item_get_key(noAtual->item) != key)) {
            noAnterior = noAtual;
            noAtual = noAtual->next;
        }
        if (noAtual != NULL) {
            if (noAtual == list->start) {
                list->start = noAtual->next;
                noAtual->next = NULL;
            } else {
                noAnterior->next = noAtual->next;
                noAtual->next = NULL;
            }
            if (list->end == noAtual) {
                list->end = noAnterior;
            }
            return TRUE;
        }
    }
    return FALSE;
}