#ifndef TREE_H
#define TREE_H
//Importei a game.h para que as funções print_item,get_key,get_game_name e erase_item fizessem sentido, não sei como resolver isso
//mas acredito que se eu for reutilizar essa estrutura, terei de criar funções com os mesmos nomes :)
#include "../Game/game.h" 
#include "../Util/util.h"

typedef int TYPE_KEY; // necessário definir

typedef struct avl_tree_st AVL_TREE;

AVL_TREE *create_tree();
boolean insert_tree(AVL_TREE *tree, void *item);
boolean erase_tree(AVL_TREE **tree);
boolean remove_tree_item(AVL_TREE *tree, TYPE_KEY key);
GAME *search_tree(AVL_TREE *tree, TYPE_KEY key);
void pre_order_tree(AVL_TREE *tree);
void in_order_tree(AVL_TREE *tree);
void pos_order_tree(AVL_TREE *tree);

#endif // TREE_H