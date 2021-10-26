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
    NODE *head;
    NODE *tail;
    int size;
};

LIST *create_list() {
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list != NULL) {
        list->head = (NODE *)malloc(sizeof(NODE));
        list->head->item = create_empty_item();
        if (list->head == NULL)
            return NULL;
        list->head->next = NULL;
        list->tail = NULL;
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
                list->head->next = new_node;
                new_node->previous = list->head;
            } else {
                new_node->previous = list->tail;
                list->tail->next = new_node;
            }
            list->tail = new_node;
            list->tail->next = list->head;
            list->size++;
            return TRUE;
        }
    }
    return ERRO_LIST;
}

boolean list_empty(const LIST *list) {
    if (list != NULL) {
        return list->head->next == NULL;
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
        actual_node = list->head->next;
        while (actual_node != NULL && get_key(actual_node->item) != key) {
            actual_node = actual_node->next;
        }
        if (actual_node != NULL) {
            if (actual_node == list->head) {
                list->head = actual_node->next;
                actual_node->next = NULL;
            } else {
                actual_node->previous = actual_node->next;
                actual_node->next = NULL;
            }
            if (actual_node == list->tail) {
                list->tail = actual_node->previous;
            }
            return TRUE;
        }
    }
    return FALSE;
}

GAME *sequential_search(const LIST *list, int key) {
    set_key(list->head->item, key);
    NODE *nodeAtual = list->head;
    do {
        nodeAtual = nodeAtual->next;
    } while (get_key(nodeAtual->item) != key);
    return ((nodeAtual != list->head) ? nodeAtual->item : NULL);
}

boolean list_erase(LIST **list) {
    if ((*list != NULL) && (!list_empty(*list))) {
        while ((*list)->size >= 0) {
            NODE *temporaryNode;
            temporaryNode = (*list)->head;
            (*list)->head = (*list)->head->next;
            free(temporaryNode->item);
            temporaryNode->item = NULL;
            temporaryNode->next = NULL;
            temporaryNode->previous = NULL;
            free(temporaryNode);
            temporaryNode = NULL;
            (*list)->size -= 1;
        }
        free(*list);
        *list = NULL;
        return TRUE;
    }
    return FALSE;
}