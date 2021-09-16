#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GAME *create_catalog(int size) {
    GAME *game = (GAME *)malloc(sizeof(GAME *) * size);

    if (game == NULL)
        exit(EXIT_FAILURE);

    return game;
}

GAME *realloc_catalog(GAME *game, int *size) {
    *size *= 1.15; //Aumenta 15% do limite de games registrados
    game = (GAME *)realloc(game, sizeof(GAME *) * (*size));

    if (game == NULL)
        exit(EXIT_FAILURE);
    
    return game;
}

char **create_found_games_catalog(int size_search) {
    char **found_games = (char **)malloc(sizeof(char *) * size_search);

    if (found_games == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < size_search; i++) {
        found_games[i] = (char *)malloc(sizeof(char) * 256);
        if (found_games[i] == NULL)
            exit(EXIT_FAILURE);
    }
    return found_games;
}

char **realloc_found_games_catalog(char **found_games, int *size_search) {
    *size_search *= 1.35; //Aumenta 35% do limite de pesquisa
    found_games = (char **)realloc(found_games, sizeof(char *) * (*size_search));

    if (found_games == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < *size_search; i++) {
        found_games[i] = (char *)realloc(found_games[i], sizeof(char) * 256);
        if (found_games[i] == NULL)
            exit(EXIT_FAILURE);
    }
    return found_games;
}

void print_found_games(const char **found_games, int number_of_searches) {
    for (int i = 0; i < number_of_searches; i++) {
        printf("%s\n", found_games[i]);
    }
}

void free_found_games_catalog(char **found_games, int size) {
    for (int i = 0; i < size; i++)
        free(found_games[i]);
    free(found_games);
}