#include <stdio.h>
#include "Pilha.h"
#include "Util.h"

void testeEmpilhaEDesempilha();
void testeEmpilhaMuitos();

int main()
{
    testeEmpilhaEDesempilha();
    testeEmpilhaMuitos();
    return 0;
}

void testeEmpilhaEDesempilha()
{
    PILHA *pilha;
    pilha = pilha_criar();
    ITEM *item = item_criar(0, "Exodia", 100, 100);
    pilha_empilhar(pilha, item);
    item_imprimir(pilha_topo(pilha));
    item_imprimir(pilha_desempilhar(pilha));
    boolean_print(pilha_vazia(pilha));
    pilha_apagar(&pilha);
}

void testeEmpilhaMuitos()
{
    PILHA *pilha;
    pilha = pilha_criar();
    ITEM *item = item_criar(0, "Exodia, The Forbidden One", 1000, 1000);
    pilha_empilhar(pilha, item);
    item = item_criar(0, "Blue Eyes White Dragon", 3000, 2500);
    pilha_empilhar(pilha, item);
    item_imprimir(pilha_topo(pilha));
    item_imprimir(pilha_desempilhar(pilha));
    boolean_print(pilha_vazia(pilha));
    pilha_apagar(&pilha);
}
