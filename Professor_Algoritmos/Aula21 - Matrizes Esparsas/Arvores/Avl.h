#ifndef TADGENERICO_AVL_H
#define TADGENERICO_AVL_H

#include "../Item.h"

typedef int boolean;

#define max(a, b) ((a > b) ? a : b)
typedef struct avl AVL;

void avl_apagar(AVL **arvore);
AVL *avl_criar();
boolean avl_inserir(AVL *arvore, const ITEM *item);

#endif //TADGENERICO_AVL_H
