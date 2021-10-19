#include "game.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_st {
    char name[256];
    char producer[256];
    int year;
    int key;
};

GAME *register_game(char *name, char *producer, int year, int key) {
    GAME *game = (GAME *)malloc(sizeof(GAME));
    if (game == NULL)
        exit(EXIT_FAILURE);

    strcpy(game->name, name);
    strcpy(game->producer, producer);
    game->year = year;
    game->key = key;

    return game;
}

int get_key(const GAME *game) {
    if (game != NULL)
        return game->key;

    return ERRO;
}