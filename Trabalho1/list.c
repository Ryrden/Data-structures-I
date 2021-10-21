#include "list.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st {
    GAME *item;
    NODE *next;
    NODE *previous;
};

struct list {
    NODE *sentinel;
    NODE *end;
    int size;
};

LIST *create_list() {
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list != NULL) {
        list->sentinel = (NODE *)malloc(sizeof(NODE));
        list->sentinel->item = create_empty_item();
        if (list->sentinel == NULL)
            return NULL;
        list->sentinel->next = NULL;
        list->end = NULL;
        list->size = 0;
    }
    return list;
}

int list_insert(LIST *list, GAME *item) {
    if (list != NULL) {
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        if (new_node != NULL) {
            new_node->item = item;
            if (list_empty(list)) {
                list->sentinel->next = new_node;
                new_node->previous = list->sentinel;
            } else {
                new_node->previous = list->end;
                list->end->next = new_node;
            }
            list->end = new_node;
            list->end->next = list->sentinel;
            list->size++;
            return TRUE;
        }
    }
    return ERRO_LIST;
}

boolean list_empty(const LIST *list) {
    if (list != NULL) {
        return list->sentinel->next == NULL;
    }
    return ERRO_LIST;
}

int list_size(const LIST *list) {
    if (list != NULL) {
        return list->size;
    }
    return ERRO_LIST;
}

boolean list_remove_item(LIST *list, int key) {
    if (list != NULL) {
        NODE *actual_node;
        NODE *previous_node = NULL;
        actual_node = list->sentinel->next;
        while (actual_node != NULL && get_key(actual_node->item) != key) {
            previous_node = actual_node;
            actual_node = actual_node->next;
        }
        if (actual_node != NULL) {
            if (actual_node == list->sentinel) {
                list->sentinel = actual_node->next;
                actual_node->next = NULL;
            } else {
                previous_node->next = actual_node->next;
                actual_node->next = NULL;
            }
            if (list->end == actual_node) {
                list->end = previous_node;
            }
            return TRUE;
        }
    }
    return FALSE;
}

GAME *sequential_search(const LIST *list, int key) {
    set_key(list->sentinel->item, key);
    NODE *nodeAtual = list->sentinel;
    do {
        nodeAtual = nodeAtual->next;
    } while (get_key(nodeAtual->item) != key);
    return ((nodeAtual != list->sentinel) ? nodeAtual->item : NULL);
}

boolean list_erase(LIST **list) {
    if ((*list != NULL) && (!list_empty(*list))) {
        while ((*list)->sentinel != NULL) {
            NODE *temporaryNode;
            temporaryNode = (*list)->sentinel;
            (*list)->sentinel = (*list)->sentinel->next;
            free(temporaryNode->item);
            temporaryNode->item = NULL;
            temporaryNode->next = NULL;
            free(temporaryNode);
            temporaryNode = NULL;
        }
        free(*list);
        *list = NULL;
        return TRUE;
    }
    return FALSE;
}