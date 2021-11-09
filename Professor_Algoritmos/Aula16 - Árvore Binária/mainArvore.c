#include <stdio.h>
#include "Arvores/ArvoreBinaria.h"

int main()
{
    ARVORE_BINARIA *arvoreBinaria;
    arvoreBinaria = arvore_binaria_criar();
    arvore_binaria_pre_ordem(arvoreBinaria);
    arvore_binaria_em_ordem(arvoreBinaria);
    arvore_binaria_pos_ordem(arvoreBinaria);
    return 0;
}