#include "list.h"
#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st {
    BIG_NUMBER *item;
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
    return ERRO_LIST;
}

int list_size(const LIST *list) {
    if (list != NULL) {
        return list->size;
    }
    return ERRO_LIST;
}

int list_insert(LIST *list, BIG_NUMBER *item) {
    if (list != NULL) {
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        if (new_node != NULL) {
            new_node->item = item;
            new_node->next = NULL;
            if (list_empty(list)) {
                list->start = new_node;
            } else {
                list->end->next = new_node;
            }
            list->end = new_node;
            list->size++;
            return TRUE;
        }
    }
    return ERRO_LIST;
}

boolean list_remove_item(LIST *list, int key) {
    if (list != NULL) {
        NODE *actual_node;
        NODE *previous_node = NULL;
        actual_node = list->start;
        while (actual_node != NULL /*&& (item_get_key(actual_node->item) != key)*/) {
            previous_node = actual_node;
            actual_node = actual_node->next;
        }
        if (actual_node != NULL) {
            if (actual_node == list->start) {
                list->start = actual_node->next;
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

BIG_NUMBER *sequential_search(const LIST *list, int key) {
    if (list != NULL) {
        NODE *actual_node;
        actual_node = list->start;
        while (actual_node != NULL) {
            if (get_key(actual_node->item) == key)
                return actual_node->item;
            actual_node = actual_node->next;
        }
    }
    return NULL;
}

boolean list_erase(LIST **list) {
    if ((*list != NULL) && (!list_empty(*list))) {
        while ((*list)->start != NULL) {
            NODE *temporaryNode;
            temporaryNode = (*list)->start;
            (*list)->start = (*list)->start->next;
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
