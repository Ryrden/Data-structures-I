#ifndef STRUCT_LIST_H
#define STRUCT_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define NOpcoes 3
#define NCursos 7

typedef int TipoChave;

typedef struct {
    TipoChave Chave;
    int NotaFinal;
    int Opcao[NOpcoes];
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str {
    TipoItem Item;
    Apontador Prox;
} Celula;

typedef struct {
    Apontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(TipoItem x, TipoLista *Lista);

void Retira(Apontador p, TipoLista *Lista, TipoItem *Item);

void Imprime(TipoLista Lista);

void LeRegistro(TipoItem *Registro);

#endif