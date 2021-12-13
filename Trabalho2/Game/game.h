#ifndef JOGO_H
#define JOGO_H
#include "../Util/util.h"
#include "../Game/game.h"

typedef struct game_st GAME;

void register_game(GAME *game, char *name, char *producer, int year, int key);

void print_game(GAME *game);

int get_key(const GAME *game);

char *get_game_name(GAME *game);

void print_item(GAME *game);

GAME *create_empty_item();

GAME *create_game();

void erase_item(GAME *game);

boolean swap_games(GAME *game1, GAME *game2);

boolean compare_games(GAME *game1, GAME *game2);

boolean copy_games(GAME *game1, GAME *game2);

char *search_producer(GAME *game, char *game_producer);

char *search_year(GAME *game, int game_year);

void print_game_name(GAME *game);

int set_key(GAME *item, int key);

#endif // JOGO_H