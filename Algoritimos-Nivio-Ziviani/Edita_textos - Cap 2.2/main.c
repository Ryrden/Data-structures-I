#define MaxTam 70
#define CancelaCarater "#"
#define CancelaLinha '\'
#define SaltaLinha "@"
#define MarcaEof
#include "pilhaSequencial.h"
#include <stdio.h>

typedef char tipo_chave;

void main() {
    PILHA pilha;
    ITEM x;

    FPvazia(&pilha);
    x.chave = getchar();
    if (x.chave == '\n') {
        x.chave = while (x.chave != MarcaEOF) {
            if (x.chave == CancelaCarater) {
                if (!Vazia(pilha))
                    desempilha(&pilha, &x);
            } else if (x.chave == CancelaLinha)
                FPvazia(&pilha);
            else if (x.chave == SaltaLinha)
                imprime(&pilha);
            else {
                if (tamanho(pilha) == MaxTam)
                    imprime(&pilha);
                empilha(x, &pilha);
            }
            x.chave = getchar();
            if (x.chave == '\n')
                x.chave == "";
        }
        if (!vazia(pilha))
            imprime(&pilha);
    }
}