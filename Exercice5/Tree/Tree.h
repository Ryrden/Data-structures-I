#ifndef TREE_H
#define TREE_H
#include "../Bank/Bank.h"
#include "../Util/util.h"

#define LEFT 0
#define RIGHT 1

typedef struct binary_tree_st BINARY_TREE;

BINARY_TREE *create_tree();
boolean erase_tree(BINARY_TREE *tree);
void pre_order_tree(BINARY_TREE *tree);
void in_order_tree(BINARY_TREE *tree);
void pos_order_tree(BINARY_TREE *tree);
boolean insert_tree(BINARY_TREE *tree, BANK *item, int side, char *key);

#endif // TREE_H