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

char **create_found_games_catalog(int size_search);

void print_found_games(char **found_games, int number_of_searches);

void free_found_games_catalog(char **found_games, int size);

#endif // CATALOG_H