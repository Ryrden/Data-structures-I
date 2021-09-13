#include <stdio.h>
#include "Item.h"

int main (void){
    ITEM *item;
    item = item_criar(1, "pipoqueira", 100.10f);
    item_imprimir(item);
    item_set_chave(item, 2);
    int chave = item_get_chave(item);
    printf("\n chave: %d\n", chave );
    item_apagar(&item);

    return 0;
}