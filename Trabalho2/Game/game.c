#include "../Game/game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game_st {
    char name[256];
    char producer[256];
    int year;
    int key;
};

void register_game(GAME *game, char *name, char *producer, int year, int key) {
    if (game != NULL) {
        strcpy(game->name, name);
        strcpy(game->producer, producer);
        game->year = year;
        game->key = key;
    }
}

GAME *create_game() {
    GAME *game = (GAME *)malloc(sizeof(GAME));
    if (game == NULL)
        exit(EXIT_FAILURE);
    return game;
}

char *search_producer(GAME *game, char *game_producer) {
    if (!strcmp(game->producer, game_producer)) {
        return game->name;
    }

    return FALSE;
}

char *search_year(GAME *game, int game_year) {
    if (game->year == game_year) {
        return game->name;
    }

    return FALSE;
}

void print_item(GAME *game) {
    printf("%s\n", game->name);
}

int get_key(const GAME *game) {
    if (game != NULL)
        return game->key;
    return ERROR;
}

GAME *create_empty_item() {
    GAME *item;

    item = (GAME *)calloc(sizeof(GAME), 1);
    if (item != NULL)
        return item;
    return NULL;
}

int set_key(GAME *item, int key) {
    if (item != NULL) {
        item->key = key;
        return TRUE;
    }
    return FALSE;
}

boolean compare_games(GAME *game1, GAME *game2) {
    if (game1 != NULL && game2 != NULL)
        if (!strcmp(game1->name, game2->name))
            if (!strcmp(game1->producer, game2->producer))
                if (game1->year == game2->year)
                    return TRUE;

    return FALSE;
}