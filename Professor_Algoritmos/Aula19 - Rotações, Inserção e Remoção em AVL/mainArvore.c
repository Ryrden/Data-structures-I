#include <stdio.h>
#include "Arvores/ArvoreBinaria.h"

void inserir_items(ARVORE_BINARIA *arvoreBinaria);

int main()
{
    ARVORE_BINARIA *arvoreBinaria;
    arvoreBinaria = arvore_binaria_criar();
    inserir_items(arvoreBinaria);
    arvore_binaria_pre_ordem(arvoreBinaria);
    arvore_binaria_em_ordem(arvoreBinaria);
    arvore_binaria_pos_ordem(arvoreBinaria);
    arvore_binaria_imprimir(arvoreBinaria);
    return 0;
}

void inserir_items(ARVORE_BINARIA *arvoreBinaria)
{
    ITEM *item = item_criar(0, "Batata", "Faz algo", 100, 100);
    arvore_binaria_inserir(arvoreBinaria,item, FILHO_ESQ, 0);
    item = item_criar(1, "Cenoura", "Faz algo", 100, 100);
    arvore_binaria_inserir(arvoreBinaria,item, FILHO_ESQ, 0);
    item = item_criar(2, "Quiabo", "Faz algo", 100, 100);
    arvore_binaria_inserir(arvoreBinaria,item, FILHO_DIR, 0);
    item = item_criar(3, "Pepino", "Faz algo", 100, 100);
    arvore_binaria_inserir(arvoreBinaria,item, FILHO_DIR, 1);
    item = item_criar(4, "Picles", "Faz algo", 100, 100);
    arvore_binaria_inserir(arvoreBinaria,item, FILHO_ESQ, 1);
    item = item_criar(5, "Cebola", "Faz algo", 100, 100);
    arvore_binaria_inserir(arvoreBinaria,item, FILHO_DIR, 2);
}