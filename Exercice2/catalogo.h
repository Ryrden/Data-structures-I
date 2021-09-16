#ifndef CATALOGO_H
#define CATALOGO_H
#include "jogo.h"

GAME *create_catalog(int size);

GAME *realloc_catalog(GAME *game, int *size);

char **create_found_games_catalog(int size_search);

char **realloc_found_games_catalog(char **found_games, int *size_search);

void print_found_games(const char **found_games, int number_of_searches);

void free_found_games_catalog(char **found_games, int size);

#endif //CATALOGO_H