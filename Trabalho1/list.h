#ifndef LIST_H
#define LIST_H
#include "util.h"
#include "game.h"
#define ERRO_LIST (-300)

typedef struct list LIST;

LIST *create_list();
boolean  list_insert(LIST *list, GAME *item);
boolean list_insert_start(LIST *list, GAME *item);
boolean list_erase(LIST **list);
boolean list_remove(LIST *list);
boolean list_remove_item(LIST *list, int key);
int list_size(const LIST *list);
boolean list_empty(const LIST *list);
boolean list_full(const LIST *list);
GAME *sequential_search(const LIST *list, int key);
void print_list(const LIST *list);
void decrease_list_size(LIST *list, int to_remove);
GAME *previous_item(const LIST *list, int key);
GAME *next_item(const LIST *list, int key);

#endif // LIST_H
