#include "struct_list.h"

void FLVazia(TipoLista *Lista) { //Faz a lista ficar Vazia
    Lista->Primeiro = (Apontador)malloc(sizeof(Celula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) { //Esta função retorna true se a lista está vazia; senão retorna false
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) { //Insere x após o último item da lista
    Lista->Ultimo->Prox = (Apontador)malloc(sizeof(Celula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(Apontador p, TipoLista *Lista, TipoItem *Item) { /*Retorna o item x que está na posição p da lista,
    retirando-o da lista e deslocando os itens a partir da posição p+l para
    as posições anteriores.
    */
    Apontador q;

    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf(" Erro: Lista vazia ou posição não existe\n");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if (p->Prox == NULL)
        Lista->Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista) { //Imprime os itens da lista na ordem de ocorrência.
    Apontador Aux;

    Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("%12d\n", Aux->Item.Chave);
    }
}

void LeRegistro(TipoItem *Registro) { //LêRegistro
    /*Os valores lidos devem estar separados por brancos --*/
    int i;

    scanf("%d %d", &Registro->Chave, &Registro->NotaFinal);
    for (i = 0; i < NOpcoes; i++) {
        scanf("%d", &Registro->Opcao[i]);
    }
}