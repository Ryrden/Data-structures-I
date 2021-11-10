#ifndef TREE_H
#define TREE_H
#include "../Util/util.h"

#define LEFT 0
#define RIGHT 1

typedef struct tree_st TREE;

TREE *create_tree();
NODE *create_tree_node(void *item);
boolean erase_tree(TREE **tree);
void pre_order_tree(TREE *tree);
void in_order_tree(TREE *tree);
void pos_order_tree(TREE *tree);
boolean insert_tree(TREE *tree, void *item, int side, int key);

#endif // TREE_H