#ifndef CATALOG_H
#define CATALOG_H
#include "util.h"

typedef enum {
    produtora = 1,
    ano,
    imprime,
    posicao,
    mover_direita,
    mover_esquerda,
    encerrar
} operation;

operation select_command(char *command);

#endif // CATALOG_H