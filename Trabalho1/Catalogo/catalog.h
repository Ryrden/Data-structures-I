#ifndef CATALOG_H
#define CATALOG_H
#include "../Util/util.h"
#define INEXISTENT_KEY (-32000)

typedef enum {
    remove_duplicados = 1,
    produtora,
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

int *create_duplicate_games(int registers);

void ajust_duplicate_key_games(int *duplicate_games, int N, int key);

void free_duplicate_games(int **duplicate_games);

#endif // CATALOG_H