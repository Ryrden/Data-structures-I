#include <stdio.h>
#include <stdlib.h>

#include "Lista/Lista.h"

void testeEmpilhaStdin();

int main() {
    testeEmpilhaStdin();
}

void testeEmpilhaStdin()
{
    LISTA *lista;
    lista = lista_criar();
    ITEM *item = item_ler_std_in();
    lista_inserir(lista, item);
    item = item_ler_std_in();
    lista_inserir(lista, item);
    item_imprimir(lista_busca_sequencial(lista, 1));
    item_imprimir(lista_busca_sequencial(lista, 1));
    boolean_print(lista_vazia(lista));
    lista_apagar(&lista);
}
