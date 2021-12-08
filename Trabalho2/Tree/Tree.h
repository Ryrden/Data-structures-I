#ifndef TREE_H
#define TREE_H
#include "../Game/game.h" //Importei para que as funções print_item e get_key fizessem sentido, não sei como resolver isso
#include "../Util/util.h"

typedef int TYPE_KEY; // necessário definir

typedef struct avl_tree_st AVL_TREE;

AVL_TREE *create_tree();
boolean insert_tree(AVL_TREE *tree, GAME *item);
boolean erase_tree(AVL_TREE **tree);
boolean remove_tree(AVL_TREE *tree, TYPE_KEY key);
GAME *search_tree(AVL_TREE *tree, TYPE_KEY key);
void pre_order_tree(AVL_TREE *tree);
void in_order_tree(AVL_TREE *tree);
void pos_order_tree(AVL_TREE *tree);

#endif // TREE_H