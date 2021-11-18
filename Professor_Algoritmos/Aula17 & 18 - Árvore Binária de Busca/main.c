#include <stdio.h>
#include "EstruturasLineares/EstruturaGenerica.h"
#include "Item.h"
#include "EstruturasLineares/PilhaEncadeada.h"
#include "EstruturasLineares/ListaEncadeada.h"
#include "EstruturasLineares/ListaCircular.h"

#define TIPO_PILHA_ENCADEADA 0
#define TIPO_LISTA_ENCADEADA 1
#define TIPO_LISTA_CIRCULAR 2

void boolean_print(boolean bool);

int main() {
    int dataStructureSelector;

    ESTRUTURA_GENERICA* (*criar_ptr)();
    int (*inserir_ptr)(ESTRUTURA_GENERICA *, ITEM*);
    int (*remover_ptr)(ESTRUTURA_GENERICA *, ITEM*);
    boolean (*apagar_ptr)(ESTRUTURA_GENERICA **);
    boolean (*vazia_ptr)(const ESTRUTURA_GENERICA*);

    scanf("%d", &dataStructureSelector);

    switch (dataStructureSelector) {
        case TIPO_PILHA_ENCADEADA:
            criar_ptr = &pilha_criar;
            inserir_ptr = &pilha_empilhar;
            apagar_ptr = &pilha_apagar;
            vazia_ptr = &pilha_vazia;
            break;
        case TIPO_LISTA_ENCADEADA:
            criar_ptr = &lista_criar;
            inserir_ptr = &lista_inserir;
            apagar_ptr = &lista_apagar;
            vazia_ptr = &lista_vazia;
            break;
        case TIPO_LISTA_CIRCULAR:
            criar_ptr = &lista_circular_criar;
            inserir_ptr = &lista_circular_inserir;
            apagar_ptr = &lista_circular_apagar;
            vazia_ptr = &lista_circular_vazia;
            break;
        default:
            criar_ptr = &pilha_criar;
            inserir_ptr = &pilha_empilhar;
            apagar_ptr = &pilha_apagar;
            vazia_ptr = &pilha_vazia;
            break;
    }

    ESTRUTURA_GENERICA *estruturaGenerica;
    estruturaGenerica = criar_ptr();
    ITEM *item = NULL;
    inserir_ptr(estruturaGenerica, item);
    boolean_print(vazia_ptr(estruturaGenerica));
    apagar_ptr(&estruturaGenerica);
}

void boolean_print(boolean bool)
{
    if(bool == TRUE)
    {
        printf("TRUE\n");
    }
    else if(bool == FALSE)
    {
        printf("FALSE\n");
    }
    else
    {
        printf("ERRO\n");
    }
}