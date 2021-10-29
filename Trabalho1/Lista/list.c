#include "../Lista/list.h"
#include "../Game/game.h"
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
        list->head->previous = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

boolean list_insert(LIST *list, GAME *item) {
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
            list->head->previous = new_node;
            list->size++;
            return TRUE;
        }
    }
    return ERRO_LIST;
}

boolean list_insert_start(LIST *list, GAME *item) {
    if ((list != NULL)) {
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        if (new_node != NULL) {
            new_node->item = item;
            if (list_empty(list)) {
                list->tail = new_node;
                list->tail->next = list->head;
                list->head->previous = list->tail;
            } else {
                list->head->next->previous = new_node;
                new_node->next = list->head->next;
            }
            new_node->previous = list->head;
            list->head->next = new_node;
            list->size++;
            return TRUE;
        }
    }
    return FALSE;
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
                actual_node->previous->next = actual_node->next;
                actual_node->next->previous = actual_node->previous;
                actual_node->next = NULL;
            }
            if (actual_node == list->tail) {
                list->tail = actual_node->previous;
            }
            actual_node = NULL;
            list->size--;
            return TRUE;
        }
    }
    return FALSE;
}

GAME *sequential_search(const LIST *list, int key) {
    set_key(list->head->item, key);
    NODE *actual_node = list->head;
    do {
        actual_node = actual_node->next;
    } while (get_key(actual_node->item) != key);
    return ((actual_node != list->head) ? actual_node->item : NULL);
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

void decrease_list_size(LIST *list, int to_remove) {
    if (list != NULL) {
        list->size -= to_remove;
    }
}

GAME *previous_item(const LIST *list, int key) {
    if (list != NULL) {
        NODE *actual_node;
        actual_node = list->head->next;
        while (actual_node != NULL) {
            if (get_key(actual_node->item) == key) {
                if (actual_node->previous == list->head)
                    return actual_node->previous->previous->item;
                else
                    return actual_node->previous->item;
            }
            actual_node = actual_node->next;
        }
    }
    return NULL;
}

GAME *next_item(const LIST *list, int key) {
    if (list != NULL) {
        NODE *actual_node;
        actual_node = list->head->next;
        while (actual_node != NULL) {
            if (get_key(actual_node->item) == key) {
                if (actual_node->next == list->head)
                    return actual_node->next->next->item;
                else
                    return actual_node->next->item;
            }
            actual_node = actual_node->next;
        }
    }
    return NULL;
}