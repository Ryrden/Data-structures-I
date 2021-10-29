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

void print_game_name(GAME *game) {
    printf("%s\n", game->name);
}

boolean swap_games(GAME *game1, GAME *game2) {

    if (game1 != NULL && game2 != NULL) {
        char temp_name[256];
        char temp_producer[256];
        int temp_year;

        strcpy(temp_name, game1->name);
        strcpy(temp_producer, game1->producer);
        temp_year = game1->year;

        strcpy(game1->name, game2->name);
        strcpy(game1->producer, game2->producer);
        game1->year = game2->year;

        strcpy(game2->name, temp_name);
        strcpy(game2->producer, temp_producer);
        game2->year = temp_year;

        return TRUE;
    }
    return FALSE;
}

boolean copy_games(GAME *game1, GAME *game2) {
    if (game1 != NULL && game2 != NULL) {
        game1 = (GAME *)malloc(sizeof(GAME));
        if (game1 == NULL)
            exit(EXIT_FAILURE);

        strcpy(game1->name, game2->name);
        strcpy(game1->producer, game2->producer);
        game1->year = game2->year;

        return TRUE;
    }
    return FALSE;
}

int get_key(const GAME *game) {
    if (game != NULL)
        return game->key;

    return ERRO;
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

void decrease_key_value(GAME *game) {
    if (game != NULL) {
        game->key -= 1;
    }
}